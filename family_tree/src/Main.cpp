#include <iostream>
#include <memory>
#include "Person.hpp"
#include "FamilyTree.hpp"

using namespace std;

int main()
{
    Person grandparent(1, "Grandparent", "Lastname", "Blue", 1, 1, 1950);
    Person parent1(2, "Parent1", "Lastname", "Green", 15, 5, 1970);
    Person parent2(3, "Parent2", "Lastname", "Blue", 20, 8, 1975);
    Person child1(4, "Child1", "Lastname", "Blue", 10, 3, 2000);
    Person child2(5, "Child2", "Lastname", "Green", 12, 7, 2002);
    Person child3(6, "Child3", "Lastname", "Brown", 8, 9, 2005);

    FamilyTree<Person> f;
    f.addRoot(grandparent);

    // Ajouter un membre de la famille
    f.add(grandparent, parent1);
    f.add(grandparent, parent2);
    f.add(parent1, child1);
    f.add(parent1, child2);
    f.add(parent2, child3);

    // Calculer la taille de l’arbre généalogique
    cout << "Taille de l'arbre généalogique : " << f.numberNodes() << endl;

    // Lister la descendance d’une personne (in-order, pre-order and
    // post-order)

    vector<Person> preorder = f.listDescendantPreOrder(parent1);
    vector<Person> postorder = f.listDescendantPostOrder(grandparent);

    cout << "Descendance de " << parent1 << " (PreOrder):" << endl;
    for (const auto &p : preorder)
    {
        cout << "---" << p << endl;
    }

    cout << "Descendance de " << grandparent << " (PostOrder):" << endl;
    for (const auto &p : postorder)
    {
        cout << "---" << p << endl;
    }
    // Pour une couleur d’yeux entrée par l’utilisateur, lister les personnes
    // ayant cette couleur.
    vector<Person> green = f.filterByEyeColor("Green");
    cout << "Personnes avec les yeux verts" << endl;
    for (const auto &p : green)
    {
        cout << "---" << p << endl;
    }

    // Pour une couleur d’yeux entrée par l’utilisateur, permet de lister
    // tous les ancêtres (ainsi que lui-même) qui ont la même couleur
    vector<Person> ancestorBlue = f.listAncestorByEyeColor(child1);
    cout << "Ancêtres avec les yeux bleus:" << endl;
    for (const auto &p : ancestorBlue)
    {
        cout << "---" << p << endl;
    }
    return 0;
}
