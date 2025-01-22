#include <iostream>
#include "Player.hxx"

Player::Player(int max_gain, int max_hand)
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

float Player::computeFinalScore()
{
    return computePileScore(gain);
}

void Player::one_round_war(Player &p1, Player &p2)
{
    if (p1.hand.estVide() || p2.hand.estVide())
    {
        return;
    }

    Card c1 = p1.hand.depiler();
    Card c2 = p2.hand.depiler();

    cout << "Carte de p1: " << c1 << endl;
    cout << "Score de p1: " << c1.computeScore() << endl;

    cout << "Carte de p2: " << c2 << endl;
    cout << "Score de p2: " << c2.computeScore() << endl;

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

void Player::addCard(const Card &c)
{
    hand.empiler(c);
}