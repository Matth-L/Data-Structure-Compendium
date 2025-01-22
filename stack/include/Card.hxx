#ifndef CARD_HXX
#define CARD_HXX

#include <iostream>

class Card
{

public:
    enum class Color
    {
        RED,  // 1
        BLACK // 0
    };
    Card();
    Card(int value, int bonus, Color color);
    Card(const Card &to_copy);

    // getters
    int getValue() const;
    int getBonus() const;
    float getModifier() const;
    Color getColor() const;

    // game methods
    float computeScore() const;
    static Card generateRandomCard();

    // overloads
    Card &operator=(const Card &to_copy);
    friend std::ostream &operator<<(std::ostream &output, const Card &c);

private:
    struct uCardData
    {
        unsigned int value : 4;    // 4 bits (0-15)
        unsigned int bonus : 3;    // 3 bits (0-4)
        unsigned int modifier : 1; // 1 bit (0 = 1.0, 1 = 1.5)
        unsigned int color : 1;    // 1 bit (0 = Black, 1 = Red)
    } data;
};

#endif // CARD_HXX