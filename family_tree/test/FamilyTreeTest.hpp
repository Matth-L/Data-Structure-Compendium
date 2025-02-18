#ifndef FAMILYTREETEST_HPP
#define FAMILYTREETEST_HPP

#include <cxxtest/TestSuite.h>
#include "FamilyTree.hpp"
#include "Person.hpp"
#include <iostream>

using namespace std;

class FamilyTreeTest : public CxxTest::TestSuite
{
public:
    void testEmpty()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: empty test" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        TS_ASSERT(tree.isEmpty());

        cout << "==========================" << endl;
        cout << "      TEST: done      " << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief We add the root node
     *
     ***********************************************/
    void testSimpleAdding()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: simple adding + counting leaves" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "foo", "bar", "Blue", 1, 1, 1990);
        tree.addRoot(root);
        TS_ASSERT_EQUALS(tree.numberNodes(), 1);
        TS_ASSERT_EQUALS(tree.numberLeaves(), 1);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief We add root + 2 children and check if nodes = 3, leaves = 2
     *
     ***********************************************/
    void testAddingChildren()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: adding children" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);

        TS_ASSERT_EQUALS(tree.numberNodes(), 3);
        TS_ASSERT_EQUALS(tree.numberLeaves(), 2);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Adding depth with grand children
     *
     ***********************************************/
    void testAddingGrandchildren()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: adding grandchildren" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person grandchild1(3, "3", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(child1, grandchild1);

        TS_ASSERT_EQUALS(tree.numberNodes(), 3);
        TS_ASSERT_EQUALS(tree.numberLeaves(), 1);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Checking if all the nodes belong to the set
     *
     ***********************************************/
    void testRelationships()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: checking relationships" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        TS_ASSERT(tree.exists(root));
        TS_ASSERT(tree.exists(child1));
        TS_ASSERT(tree.exists(child2));
        TS_ASSERT(tree.exists(grandchild1));

        TS_ASSERT_EQUALS(tree.getRootValue(), root);
        TS_ASSERT_EQUALS(tree.getSubTree().size(), 2);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Removing nodes and testing if the number of nodes and leave
     * are modified
     ***********************************************/
    void testRemovingNodes()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: removing nodes" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);

        TS_ASSERT_EQUALS(tree.numberNodes(), 3);

        tree.remove(root, child1);
        TS_ASSERT_EQUALS(tree.numberNodes(), 2);
        TS_ASSERT_EQUALS(tree.numberLeaves(), 1);

        tree.remove(root, child2);
        TS_ASSERT_EQUALS(tree.numberNodes(), 1);
        TS_ASSERT_EQUALS(tree.numberLeaves(), 1);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Checking the height function by adding root,child,grandchild
     * and verify if the height is correct for each node
     ***********************************************/
    void testHeight()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: checking height" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        TS_ASSERT_EQUALS(tree.height(tree.getNode(root)), 3);
        TS_ASSERT_EQUALS(tree.height(tree.getNode(child1)), 2);
        TS_ASSERT_EQUALS(tree.height(tree.getNode(child2)), 1);
        TS_ASSERT_EQUALS(tree.height(tree.getNode(grandchild1)), 1);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Testing the filtering by color, with 2 blue and 1 green, check if
     *  blue = 2
     ***********************************************/
    void testFilterByEyeColor()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: filter by eye color" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1980);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Blue", 3, 3, 2005);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);

        vector<Person> blueEyedPeople = tree.filterByEyeColor("Blue");

        TS_ASSERT_EQUALS(blueEyedPeople.size(), 2);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Verifying pre-order traversal, should give : root, child
     *
     ***********************************************/
    void testListDescendantPreOrder()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: list descendants in pre-order" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        vector<Person> descendants = tree.listDescendantPreOrder(root);

        TS_ASSERT_EQUALS(descendants.size(), 4);
        TS_ASSERT_EQUALS(descendants[0], root);
        TS_ASSERT_EQUALS(descendants[1], child1);
        TS_ASSERT_EQUALS(descendants[2], grandchild1);
        TS_ASSERT_EQUALS(descendants[3], child2);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Verifying post-order traversal, should give : child, root
     *
     ***********************************************/
    void testListDescendantPostOrder()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: list descendants in post-order" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        vector<Person> descendants = tree.listDescendantPostOrder(root);

        TS_ASSERT_EQUALS(descendants.size(), 4);
        TS_ASSERT_EQUALS(descendants[0], grandchild1);
        TS_ASSERT_EQUALS(descendants[1], child1);
        TS_ASSERT_EQUALS(descendants[2], child2);
        TS_ASSERT_EQUALS(descendants[3], root);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Verifying in-order traversal, should give :
     * left half, root, right half
     ***********************************************/
    void testListDescendantInOrder()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: list descendants in in-order" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Brown", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Black", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        vector<Person> descendants = tree.listDescendantInOrder(root);

        TS_ASSERT_EQUALS(descendants.size(), 4);
        TS_ASSERT_EQUALS(descendants[0], child1);
        TS_ASSERT_EQUALS(descendants[1], grandchild1);
        TS_ASSERT_EQUALS(descendants[2], root);
        TS_ASSERT_EQUALS(descendants[3], child2);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }

    /**********************************************
     * @brief Listing ancestors by color, granchild1 = blue , total in family
     * with blue eye = 3, is the list equal 3 ?
     * Same with child 1 , which is the only one with green eye, list equal 1 ?
     ***********************************************/
    void testListAncestorByEyeColor()
    {
        cout << "\n==========================" << endl;
        cout << "      TEST: list ancestors by eye color" << endl;
        cout << "==========================" << endl;

        FamilyTree<Person> tree;
        Person root(1, "1", "foobar", "Blue", 1, 1, 1990);
        Person child1(2, "2", "foobar", "Green", 2, 2, 2000);
        Person child2(3, "3", "foobar", "Blue", 3, 3, 2005);
        Person grandchild1(4, "4", "foobar", "Blue", 4, 4, 2020);

        tree.addRoot(root);
        tree.add(root, child1);
        tree.add(root, child2);
        tree.add(child1, grandchild1);

        set<Person> ancestors = tree.listAncestorByEyeColor(grandchild1);
        set<Person> ancestors2 = tree.listAncestorByEyeColor(child1);

        TS_ASSERT_EQUALS(ancestors.size(), 3);
        TS_ASSERT_EQUALS(ancestors2.size(), 1);

        cout << "==========================" << endl;
        cout << "      TEST: done" << endl;
        cout << "==========================" << endl;
    }
};

#endif // FAMILYTREETEST_HPP
