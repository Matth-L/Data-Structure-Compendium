#include <iostream>
#include <memory>
#include "Person.hpp"
#include "FamilyTree.hpp"

using namespace std;

int main()
{
    // ancetre commun pour faciliter la mise en place de l'arbre
    // il n'est pas compté pour le reste
    Person root(0, "Root", "Root", "", 1, 1, 0);

    Person gfatherA(1, "Grand-Père", "A", "Brown", 60, 20, 1940);
    Person gmotherA(2, "Grand-Mère", "A", "Brown", 58, 18, 1942);
    Person parentA(3, "Père", "A", "Brown", 40, 15, 1970);

    Person gfatherB(4, "Grand-Père", "B", "Blue", 62, 22, 1938);
    Person gmotherB(5, "Grand-Mère", "B", "Blue", 61, 21, 1940);
    Person parentB(6, "Mère", "B", "Blue", 38, 13, 1972);

    Person child(7, "Enfant", "AB", "Brown", 10, 5, 2000);

    FamilyTree<Person> familyTree;

    familyTree.addRoot(root);
    familyTree.add(root, gfatherA);
    familyTree.add(root, gmotherA);
    familyTree.add(root, gfatherB);
    familyTree.add(root, gmotherB);

    familyTree.createCouple(gfatherA, gmotherA);
    familyTree.createCouple(gfatherB, gmotherB);

    familyTree.addChildToCouple(gfatherA, gmotherA, parentA);
    familyTree.addChildToCouple(gfatherB, gmotherB, parentB);

    familyTree.addChildToCouple(parentA, parentB, child);

    familyTree.commonAncestor();

    cout << "---------------------------------" << endl;

    cout << "Taille de l'arbre généalogique : "
         << familyTree.numberNodes()
         << endl;

    cout << "---------------------------------" << endl;

    // Lister la descendance d’une personne (pre-order)
    vector<Person> preorder = familyTree.listDescendantPreOrder(parentA);
    cout << "Descendance de " << parentA << " (PreOrder):" << endl;
    for (const auto &p : preorder)
    {
        cout << "---" << p << endl;
    }

    cout << "---------------------------------" << endl;

    // Lister la descendance d’une personne (post-order)
    vector<Person> postorder = familyTree.listDescendantPostOrder(gfatherA);
    cout << "Descendance de " << gfatherA << " (PostOrder):" << endl;
    for (const auto &p : postorder)
    {
        cout << "---" << p << endl;
    }

    cout << "---------------------------------" << endl;

    // Lister les personnes ayant une couleur d'yeux spécifique
    vector<Person> blueEyes = familyTree.filterByEyeColor("Blue");
    cout << "Personnes avec les yeux bleus :" << endl;
    for (const auto &p : blueEyes)
    {
        cout << "---" << p << endl;
    }
    cout << "---------------------------------" << endl;

    // Lister tous les ancêtres (ainsi que lui-même) qui ont la même couleur d'yeux
    set<Person> ancestorBlueEyes = familyTree.listAncestorByEyeColor(child);
    cout << "Ancêtres avec les yeux de la couleur de" << child << endl;
    for (const auto &p : ancestorBlueEyes)
    {
        cout << "---" << p << endl;
    }
    cout << "---------------------------------" << endl;

    // Moyenne d'age
    cout << "Moyenne d'age de la famille : " << familyTree.averageAge() << endl;

    cout << "---------------------------------" << endl;

    return 0;
}
