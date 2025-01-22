#include <cxxtest/TestSuite.h>
#include "include/Pile.hxx"

class PileTest : public CxxTest::TestSuite
{
public:
    // Test 1 : Création
    void testCreationPile(void)
    {
        cout << "\nTest 1 : Création d'une pile" << endl;
        Pile<int> pile(1);
        TS_ASSERT_EQUALS(pile.taille(), 0);
        TS_ASSERT(pile.estVide());
        cout << "Test 1 réussi" << endl;
    }

    // Test 2 : Empiler
    void testEmpiler(void)
    {
        cout << "Test 2 : Empilage d'éléments" << endl;
        Pile<int> pile(3);
        pile.empiler(1);
        pile.empiler(2);
        pile.empiler(3);

        TS_ASSERT_EQUALS(pile.taille(), 3);
        cout << "Test 2 : Taille de la pile correcte" << endl;
        TS_ASSERT_EQUALS(pile.sommet(), 3);
        cout << "Test 2 : Sommet de la pile correct" << endl;
        cout << "Test 2 réussi" << endl;
    }

    // Test 3 : Dépiler
    void testDepiler(void)
    {
        cout << "Test 3 : Dépilage d'éléments" << endl;
        Pile<int> pile(3);
        pile.empiler(1);
        pile.empiler(2);
        pile.empiler(3);

        TS_ASSERT_EQUALS(pile.depiler(), 3);
        TS_ASSERT_EQUALS(pile.taille(), 2);
        TS_ASSERT_EQUALS(pile.sommet(), 2);
        cout << "Test 3 réussi" << endl;
    }

    // Test 4 : test de vacuité
    void testEstVide(void)
    {
        cout << "Test 4 : Test de vacuité" << endl;
        Pile<int> pile(3);
        TS_ASSERT(pile.estVide());

        pile.empiler(1);
        TS_ASSERT(!pile.estVide());
        cout << "Test 4 réussi" << endl;
    }

    // Test 5 : Sommet
    void testSommet(void)
    {
        cout << "Test 5 : Sommet de la pile" << endl;
        Pile<int> pile(3);
        pile.empiler(1);
        pile.empiler(2);

        TS_ASSERT_EQUALS(pile.sommet(), 2);
        cout << "Test 5 réussi" << endl;
    }

    // Test 6 : Dépiler une pile sans élements
    void testDepilerPileVide(void)
    {
        cout << "Test 6 : Dépiler une pile sans élements" << endl;
        Pile<int> pile(3);
        try
        {
            pile.depiler();
            TS_FAIL("Expected std::logic_error");
        }
        catch (const std::logic_error &e)
        {
            TS_ASSERT(true);
        }
        cout << "Test 6 réussi" << endl;
    }

    // Test 7 : Empiler une pile pleine
    void testEmpilerPilePleine(void)
    {
        cout << "Test 7 : Empiler une pile pleine" << endl;
        Pile<int> pile(2);
        pile.empiler(1);
        pile.empiler(2);

        try
        {
            pile.empiler(3);
            TS_FAIL("Expected std::length_error");
        }
        catch (const std::length_error &e)
        {
            TS_ASSERT(true);
        }
        cout << "Test 7 réussi" << endl;
    }

    // Test 8 : Test copie
    void testConstructeurCopie(void)
    {
        cout << "Test 8 : Constructeur de copie" << endl;
        Pile<int> pile1(3);
        pile1.empiler(1);
        pile1.empiler(2);

        Pile<int> pile2(pile1);

        TS_ASSERT_EQUALS(pile2.taille(), 2);
        TS_ASSERT_EQUALS(pile2.sommet(), 2);
        cout << "Test 8 réussi" << endl;
    }

    // Test 9 : Opérateur =
    void testEquals(void)
    {
        cout << "Test 9 : Opérateur =" << endl;
        Pile<int> pile1(3);
        pile1.empiler(1);
        pile1.empiler(2);

        Pile<int> pile2(2);
        pile2 = pile1;

        TS_ASSERT_EQUALS(pile2.taille(), 2);
        TS_ASSERT_EQUALS(pile2.sommet(), 2);
        cout << "Test 9 réussi" << endl;
    }

    // Test 10 : Print
    void testAffichage(void)
    {
        cout << "Test 10 : Affichage" << endl;
        Pile<int> pile(3);
        pile.empiler(1);
        pile.empiler(2);

        std::ostringstream oss;
        oss << pile;

        TS_ASSERT_EQUALS(oss.str(), "[1, 2].");
        cout << "Test 10 réussi" << endl;
    }
};