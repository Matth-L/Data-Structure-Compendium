#ifndef FAMILYTREE_HPP
#define FAMILYTREE_HPP

#include <set>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Person.hpp"

using namespace std;

template <typename T>
struct FamilyTreeNode
{
    using Successors = vector<shared_ptr<FamilyTreeNode<T>>>;

    T value;                               // the node
    Successors children;                   // a vector of children
    shared_ptr<FamilyTreeNode<T>> partner; // the partner

    FamilyTreeNode(const T &val) : value(val) {}
};

template <typename T>
class FamilyTree
{
private:
    using tSet = set<T>;
    using TreeNodePtr = shared_ptr<FamilyTreeNode<T>>;

    TreeNodePtr root;
    tSet family;

    /**************************************************************************
     * Helpers function
     *************************************************************************/

    /**********************************************
     * @brief Count the number of child without successors
     *
     * @param node the node from where we count the leaves
     * @return int the number of leaves
     ***********************************************/
    int countLeaves(const TreeNodePtr &node) const
    {
        if (!node)
            return 0; // nullptr
        if (node->children.empty())
            return 1; // leaves

        int leafCount = 0;
        for (const auto &child : node->children)
        {
            // count all the leaves from all the child
            leafCount += countLeaves(child);
        }
        return leafCount;
    }

    /**********************************************
     * @brief Getters for a node
     *
     * @param node the node from where we will start searching
     * @param value the value of the node we are looking for
     * @return TreeNodePtr the node
     ***********************************************/
    TreeNodePtr getNodePrivate(const TreeNodePtr &node, const T &value) const
    {
        if (!node || node->value == value)
            return node;
        for (const auto &child : node->children)
            if (auto res = getNodePrivate(child, value))
                return res;
        return nullptr;
    }

    /**************************************************************************
     * Traversal
     *************************************************************************/

    /**********************************************
     * @brief Private pre order traversal of a family tree
     * @note visit himself, then child recusively
     *
     * @param node the node
     * @param result the vector containing all the child
     ***********************************************/
    void preOrderTraversal(const TreeNodePtr &node, vector<T> &result)
    {
        if (!node)
            return;
        result.push_back(node->value); // himself
        for (const auto &child : node->children)
        {
            // child recursively
            preOrderTraversal(child, result);
        }
    }

    /**********************************************
     * @brief pre order, but only keeps element that respect color
     *
     * @param node current node
     * @param color
     * @param result the vector
     * @param cond stopping condition for recursion
     ***********************************************/
    void preOrderTraversalColor(const TreeNodePtr &node,
                                const string &color,
                                set<T> &result,
                                bool cond) // cond == true if "himself"
        const
    {

        if (cond) // adding himself
        {
            result.insert(node->value);
            return;
        }

        if (node->value.getCouleurYeux() == color)
        {
            result.insert(node->value);
        }
        for (const auto &child : node->children)
        {
            preOrderTraversalColor(child,
                                   color,
                                   result,
                                   cond || child->value == node->value); // arrived
        }
    }

    /**********************************************
     * @brief Private post order traversal of a famiy tree
     * @note visit child recursively, then himself

     * @param node the node
     * @param result the vector containing all the child
    ***********************************************/
    void postOrderTraversal(const TreeNodePtr &node, vector<T> &result)
    {
        if (!node)
            return;
        for (const auto &child : node->children)
        {
            // child recursively
            postOrderTraversal(child, result);
        }
        // himself
        result.push_back(node->value);
    }

    /**********************************************
     * @brief Visit left, root, right
     * @note I dont see the point of doing in order
     * when it's not even a binary tree, what is "left" and "right"
     *
     * @param node
     * @param result
     ***********************************************/
    void inOrder(const TreeNodePtr &node, vector<T> &result)
    {
        throw runtime_error("InOrderTraversal not supported for family tree.");
    }

public:
    FamilyTree() : root(nullptr), family() {}

    /**********************************************
     * @brief empty test, uses the set to check if the tree is empty
     *
     * @return bool
     ***********************************************/
    bool isEmpty() const
    {
        return family.empty();
    }

    /**********************************************
     * @brief Count the number of nodes in the tree, uses the set
     *
     * @return int
     ***********************************************/
    int numberNodes() const
    {
        return family.size();
    }

    /**********************************************
     * @brief Recusively count the number of children without sucessors
     * @note uses "countLeaves" which is a private method
     *
     * @return int
     ***********************************************/
    int numberLeaves() const
    {
        return countLeaves(root);
    }

    /**********************************************
     * @brief Get the Root Value
     *
     * @return T value
     ***********************************************/
    T getRootValue() const
    {
        if (root)
            return root->value;
        throw runtime_error("Root is null");
    }

    /**********************************************
     * @brief Get the Sub Tree object
     *
     * @return FamilyTreeNode<T>::Successors
     ***********************************************/
    typename FamilyTreeNode<T>::Successors getSubTree() const
    {
        if (root)
            return root->children;
        return {};
    }

    /**********************************************
     * @brief Check if the V value exist in the tree, using a set
     *
     * @param v the value
     * @return true if exists, false otherwise
     ***********************************************/
    bool exists(const T &v) const
    {
        return family.find(v) != family.end();
    }

    /**********************************************
     * @brief Get the Node object,
     *
     * @note uses getNodePrivate
     * @param value
     * @return TreeNodePtr
     ***********************************************/
    TreeNodePtr getNode(const T &value) const
    {
        return getNodePrivate(root, value);
    }

    /**********************************************
     * @brief Get the height from the current node
     *
     * @param node current node
     * @return int the height
     ***********************************************/
    int height(const TreeNodePtr &node) const
    {
        if (!node)
        {
            return 0;
        }
        if (node->children.empty())
        {
            return 1;
        }

        int maxHeight = 0;
        for (auto &it : node->children)
        {
            // getting the max from each child
            maxHeight = max(maxHeight, height(it));
        }
        return 1 + maxHeight;
    }

    /**********************************************
     * @brief add root to the tree, if root exist returns
     *
     * @param v the node root
     ***********************************************/
    void addRoot(const T &v)
    {
        if (exists(v))
            return;
        root = make_shared<FamilyTreeNode<T>>(v);
        family.insert(v);
    }

    /**********************************************
     * @brief Create the relationship parent ---- children
     * @note also adds it to the set
     *
     * @warning the ancestor is also created if it does not exist
     * @param ancestorValue  the ancestor
     * @param descendantValue the descendant, returns if it already exist
     ***********************************************/
    void add(const T &ancestorValue, const T &descendantValue)
    {
        if (exists(descendantValue))
            return;

        // creating the ancestors
        if (!exists(ancestorValue))
            addRoot(ancestorValue);

        TreeNodePtr descendantNode =
            make_shared<FamilyTreeNode<T>>(descendantValue);

        auto ancestorNode =
            getNode(ancestorValue);

        // adding the child to the ancestor vector
        if (ancestorNode)
            ancestorNode->children.push_back(descendantNode);

        // adding to the set
        family.insert(descendantValue);
    }

    /**********************************************
     * @brief remove the relationship between parents -- children
     * @note ancestor and descendant must exist
     *
     * @param ancestorValue the ancestor node
     * @param descendantValue the descendant node
     ***********************************************/
    void remove(const T &ancestorValue, const T &descendantValue)
    {
        // everything must exist
        if (isEmpty() || !exists(descendantValue) || !exists(ancestorValue))
        {
            return;
        }

        TreeNodePtr ancestorNode = getNode(ancestorValue);

        for (auto it = ancestorNode->children.begin();
             it != ancestorNode->children.end();
             ++it)
        {
            if ((*it)->value == descendantValue)
            {
                // child found == deleted
                ancestorNode->children.erase(it);
                break;
            }
        }

        family.erase(descendantValue);
    }

    /**********************************************
     * @brief Create a couple between two person
     *
     * @param person1 the first person
     * @param person2 the second person
     ***********************************************/
    void createCouple(const T &person1, const T &person2)
    {
        auto node1 = getNode(person1);
        auto node2 = getNode(person2);

        if (node1 && node2)
        {
            node1->partner = node2;
            node2->partner = node1;
        }
    }

    /**********************************************
     * @brief Create a child between two person
     *
     * @warning if they are not a couple, it will create it
     *
     * @param parent1 the first parent
     * @param parent2 the second parent
     * @param child the child
     ***********************************************/
    void addChildToCouple(const T &parent1, const T &parent2, const T &child)
    {
        auto node1 = getNode(parent1);
        auto node2 = getNode(parent2);

        if (node1->partner != node2)
        {
            createCouple(parent1, parent2);
        }

        if (node1 && node2) // check if they exist
        {
            TreeNodePtr childNode = make_shared<FamilyTreeNode<T>>(child);
            node1->children.push_back(childNode);
            node2->children.push_back(childNode);
            family.insert(child);
        }
    }
    /**************************************************************************
     * using Person.hpp
     *************************************************************************/

    /**********************************************
     * @brief Filter the eye colors using the set
     *
     * @param color eye color
     * @return vector<Person> result
     ***********************************************/
    vector<Person> filterByEyeColor(const string &color) const
    {
        vector<Person> result;
        // color found in the set = added to vector
        for (const auto &p : family)
        {
            if (p.getCouleurYeux() == color)
            {
                result.push_back(p);
            }
        }
        return result;
    }

    /**********************************************
     * @brief Compute the average using the set
     *
     * @return float
     ***********************************************/
    float averageAge()
    {
        if (family.empty())
            return 0;

        float totalAge = 0;
        // iterating over the set and getting the age every time
        for (const auto &p : family)
        {
            totalAge += p.getAge();
        }

        return totalAge / family.size();
    }

    /**********************************************
     * @brief Uses pre-order traversal to get descendant of 'value'
     *
     * @param value the node to get the descendant
     * @return vector<T> result
     ***********************************************/
    vector<T> listDescendantPreOrder(const T &value)
    {
        vector<T> res;
        auto node = getNode(value);
        if (node)
            preOrderTraversal(node, res);

        return res;
    }
    /**********************************************
     * @brief Uses post-order traversal to get descendant of 'value'
     *
     * @param value the node to get the descendant
     * @return vector<T> result
     ***********************************************/
    vector<T> listDescendantPostOrder(const T &value)
    {
        vector<T> res;
        auto node = getNode(value);
        if (node)
            postOrderTraversal(node, res);

        return res;
    }

    /**********************************************
     * @brief Uses pre-order traversal and color filtering to get the
     * descendant with the same eye color as the node
     *
     * @param value the node
     * @return vector<Person> result
     ***********************************************/
    set<Person> listAncestorByEyeColor(const Person &value) const
    {
        set<T> res;
        string color = value.getCouleurYeux();

        auto node = getNode(value);
        if (node)
        {
            preOrderTraversalColor(root, color, res, false);
        }
        return res;
    }

    /**********************************************
     * @brief If the ancestor is common, we delete the value from the set
     ***********************************************/
    void commonAncestor()
    {
        auto rootNode = getNode(root->value);
        if (rootNode)
        {
            family.erase(rootNode->value);
        }
    }
};

#endif // FAMILYTREE_HPP
