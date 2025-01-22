#include <iostream>
#include "include/Player.hxx"

int main()
{

    // Etape 1 : Créer 100 cartes aléatoirement et les mettres dans une pile
    Pile<Card> starter(100);
    for (int i = 0; i < 100; ++i)
    {
        starter.empiler(Card::generateRandomCard());
    }

    // Etape 2 : Demander à l'utilisateur combien de cartes chaque joueur aura
    unsigned char max_hand;
    std::cout << "Combien de cartes chaque joueur aura-t-il ? ";
    std::cin >> max_hand;

    // Etape 3 : Création des joueurs et attribution des cartes
    Player p1(max_hand, max_hand);
    Player p2(max_hand, max_hand);

    unsigned char number_of_rounds = 0;

    // Etape 4 : Le jeu se déroule
    while (p1.canPlay() && p2.canPlay())
    {
        p1.one_round_war(p1, p2);
        number_of_rounds++;
        cout << "Round " << number_of_rounds << endl;
    }

    // Etape 5 : Calculer et afficher les scores finaux
    int scoreP1 = p1.getScore();
    int scoreP2 = p2.getScore();

    cout << "Score de p1: " << scoreP1 << endl;
    cout << "Score de p2: " << scoreP2 << endl;
    cout << (scoreP1 > scoreP2   ? "Le joueur 1 a gagné!"
             : scoreP1 < scoreP2 ? "Le joueur 2 a gagné!"
                                 : "Egalité!")
         << endl;
}