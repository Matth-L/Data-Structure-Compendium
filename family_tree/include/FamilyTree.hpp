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
    T value;
    Successors children;
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
            return 0;
        if (node->children.empty())
            return 1;

        int leafCount = 0;
        for (const auto &child : node->children)
        {
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
        if (!node)
            return nullptr;
        if (node->value == value)
            return node;

        for (const auto &it : node->children)
        {
            if (auto res = getNodePrivate(it, value))
            {
                return res;
            }
        }
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
        result.push_back(node->value);
        for (const auto &child : node->children)
        {
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
                                vector<T> &result,
                                bool cond) const
    {
        if (!node || cond)
        {
            result.push_back(node->value);
            return;
        }

        if (node->value.getCouleurYeux() == color)
            result.push_back(node->value);

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
            postOrderTraversal(child, result);
        }
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
        throw runtime_error("In-order traversal is not supported for a general tree.");
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
     * @param v
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
     * @param ancestorValue  the ancestor, creates it in a new tree if it does
     * not exist
     * @param descendantValue the descendant, returns if it already exist
     ***********************************************/
    void add(const T &ancestorValue, const T &descendantValue)
    {
        if (exists(descendantValue))
            return;

        if (!exists(ancestorValue))
            addRoot(ancestorValue);

        TreeNodePtr descendantNode =
            make_shared<FamilyTreeNode<T>>(descendantValue);

        auto ancestorNode =
            getNode(ancestorValue);

        if (ancestorNode)
            ancestorNode->children.push_back(descendantNode);

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
        if (isEmpty() || !exists(descendantValue) || !exists(ancestorValue))
        {
            return;
        }

        TreeNodePtr ancestorNode = getNode(ancestorValue);
        if (!ancestorNode)
        {
            return;
        }

        for (auto it = ancestorNode->children.begin();
             it != ancestorNode->children.end();
             ++it)
        {
            if ((*it)->value == descendantValue)
            {
                ancestorNode->children.erase(it);
                break;
            }
        }

        family.erase(descendantValue);
    }

    /**************************************************************************
     * using Person.hpp
     *************************************************************************/

    /**********************************************
     * @brief List persons with a specific eye color
     ***********************************************/
    vector<Person> filterByEyeColor(const string &color) const
    {
        vector<Person> result;
        for (const auto &p : family)
        {
            if (p.getCouleurYeux() == color)
            {
                result.push_back(p);
            }
        }
        return result;
    }

    float averageAge()
    {
        if (family.empty())
            return 0;

        float totalAge = 0;
        for (const auto &p : family)
        {
            totalAge += p.getAge();
        }

        return totalAge / family.size();
    }

    vector<T> listDescendantPreOrder(const T &value)
    {
        vector<T> res;
        auto node = getNode(value);
        if (node)
            preOrderTraversal(node, res);

        return res;
    }

    vector<T> listDescendantPostOrder(const T &value)
    {
        vector<T> res;
        auto node = getNode(value);
        if (node)
            postOrderTraversal(node, res);

        return res;
    }

    // -  Pour une couleur d’yeux entrée par l’utilisateur, permet de lister
    // tous les ancêtres (ainsi que lui-même) qui ont la même couleur.

    vector<Person> listAncestorByEyeColor(const Person &value) const
    {
        vector<T> res;
        string color = value.getCouleurYeux();

        auto node = getNode(value);
        if (node)
        {
            preOrderTraversalColor(root, color, res, false);
        }
        return res;
    }
};

#endif // FAMILYTREE_HPP
