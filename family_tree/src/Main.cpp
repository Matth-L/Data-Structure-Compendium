#include <iostream>
#include <memory>
#include "Person.hpp"
#include "FamilyTree.hpp"

using namespace std;

int main()
{
    // Create Person objects
    Person grandparent(1, "Grandparent", "Lastname", "Blue", 1, 1, 1950);
    Person parent1(2, "Parent1", "Lastname", "Green", 15, 5, 1970);
    Person parent2(3, "Parent2", "Lastname", "Brown", 20, 8, 1975);
    Person child1(4, "Child1", "Lastname", "Blue", 10, 3, 2000);
    Person child2(5, "Child2", "Lastname", "Green", 12, 7, 2002);
    Person child3(6, "Child3", "Lastname", "Brown", 8, 9, 2005);

    // Create a FamilyTree instance
    FamilyTree<Person> familyTree;

    // Add relationships to the tree
    cout << "Adding relationships..." << endl;
    familyTree.add(grandparent, parent1);
    familyTree.add(grandparent, parent2);
    familyTree.add(parent1, child1);
    familyTree.add(parent1, child2);
    familyTree.add(parent2, child3);

    // Check if the tree is empty
    cout << "Is the family tree empty? " << (familyTree.isEmpty() ? "Yes" : "No") << endl;

    // Check the number of nodes (people in the tree)
    cout << "Number of nodes (people): " << familyTree.numberNodes() << endl;

    // Check the number of leaves (people without children)
    cout << "Number of leaves: " << familyTree.numberLeaves() << endl;

    // Get the root value
    cout << "Root value (Grandparent): " << familyTree.getRootValue().getPrenom() << " " << familyTree.getRootValue().getNom() << endl;

    // Get the sub tree of the root
    cout << "Sub tree of root (children of Grandparent):" << endl;
    for (auto &child : familyTree.getSubTree())
    {
        cout << child->value.getPrenom() << " " << child->value.getNom() << endl;
    }

    // Check if specific people exist in the tree
    cout << "Does Parent1 exist in the tree? " << (familyTree.exists(parent1) ? "Yes" : "No") << endl;
    cout << "Does Person 'Nonexistent' exist in the tree? " << (familyTree.exists(Person(7, "Nonexistent", "Lastname", "Purple", 1, 1, 1990)) ? "Yes" : "No") << endl;

    // Get a node from the tree (Parent1)
    auto parentNode = familyTree.getNode(parent1);
    if (parentNode)
    {
        cout << "Node for Parent1 found: " << parentNode->value.getPrenom() << " " << parentNode->value.getNom() << endl;
    }
    else
    {
        cout << "Parent1 node not found." << endl;
    }

    // Calculate the height of the family tree starting from the root
    cout << "Height of the tree (starting from root): " << familyTree.height(make_shared<FamilyTreeNode<Person>>(familyTree.getRootValue())) << endl;

    // Remove a child from the tree and check the changes
    cout << "Removing Child2 from Parent1..." << endl;
    familyTree.remove(parent1, child2);

    // Check the number of nodes again after removal
    cout << "Number of nodes after removal: " << familyTree.numberNodes() << endl;

    // Check if the child exists after removal
    cout << "Does Child2 exist after removal? " << (familyTree.exists(child2) ? "Yes" : "No") << endl;

    // Check the number of leaves after removal (Child2 should be removed)
    cout << "Number of leaves after removal: " << familyTree.numberLeaves() << endl;

    return 0;
}
