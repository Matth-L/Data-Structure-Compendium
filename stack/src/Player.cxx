#include <iostream>
#include "include/Player.hxx"

Player::Player(unsigned char max_gain, unsigned char max_hand)
    : gain(max_gain), hand(max_hand)
{
}

Player::Player(const Player &to_copy)
    : gain(to_copy.gain), hand(to_copy.hand)
{
}

Player::~Player()
{
}

float Player::getScore() const
{
    return score;
}

float Player::computePileScore(Pile<Card> &s) const
{
    float score = 0.0f;
    Pile<Card> temp = s;
    while (!temp.estVide())
    {
        score += temp.depiler().computeScore();
    }
    return score;
}

void Player::one_round_war(Player &p1, Player &p2)
{
    if (p1.hand.estVide() || p2.hand.estVide())
    {
        return;
    }

    Card c1 = p1.hand.depiler();
    Card c2 = p2.hand.depiler();

    Pile<Card> &mainGagnante =
        (c1.computeScore() > c2.computeScore()) ? p1.gain : p2.gain;
    mainGagnante.empiler(c1);
    mainGagnante.empiler(c2);
}

Player &Player::operator=(const Player &to_copy)
{
    gain = to_copy.gain;
    hand = to_copy.hand;
    score = to_copy.score;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Player &p)
{
    // appel à la surcharge de l'opérateur de Pile
    output << "Gain: " << p.gain << std::endl;
    output << "Hand: " << p.hand << std::endl;
    output << "Score: " << p.score << std::endl;
    return output;
}