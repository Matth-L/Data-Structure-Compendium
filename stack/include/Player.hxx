#ifndef PLAYER_HXX
#define PLAYER_HXX

#include <iostream>
#include "Pile.hxx"
#include "Card.hxx"

class Player
{

private:
    Pile<Card> gain;
    Pile<Card> hand;
    float score;

public:
    Player(int max_gain, int max_hand);
    Player(const Player &to_copy);
    ~Player();

    float getScore() const;
    void addCard(const Card &c);

    float computePileScore(Pile<Card> &c) const;

    float computeFinalScore();

    bool canPlay() const
    {
        return !hand.estVide();
    }

    /**********************************************
     * @brief Joue un tour de jeu, et transfère
     * les cartes gagnées dans la pile de gain
     *
     * @param p1 Joueur 1
     * @param p2 Joueur 2
     ***********************************************/
    void one_round_war(Player &p1, Player &p2);

    Player &operator=(const Player &to_copy);
    friend std::ostream &operator<<(std::ostream &output, const Player &p);
};

#endif // PLAYER_HXX