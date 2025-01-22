#ifndef CARD_HXX
#define CARD_HXX

#include <iostream>

class Card
{
    enum class Color
    {
        RED,
        BLACK
    };

private:
    int value;
    int bonus;
    float modifier;
    Color color;

public:
    Card();
    /**********************************************
     * @brief Construct a new Card object
     *
     * @param value
     * @param bonus
     * @param color
     ***********************************************/
    Card(int value, int bonus, Color color);

    /**********************************************
     * @brief Construct a new Card object
     *
     * @param to_copy
     ***********************************************/
    Card(const Card &to_copy);
    /**********************************************
     * @brief Get the Value object
     *
     * @return int
     ***********************************************/
    int getValue() const;

    /**********************************************
     * @brief Get the Bonus object
     *
     * @return int
     ***********************************************/
    int getBonus() const;

    /**********************************************
     * @brief Get the Modifier object
     *
     * @return float
     ***********************************************/
    float getModifier() const;

    /**********************************************
     * @brief Get the Color object
     *
     * @return Color
     ***********************************************/
    Color getColor() const;

    /**********************************************
     * @brief Compute the score of the card, .ie value * modifier * bonus
     *
     * @return float
     ***********************************************/
    float computeScore() const;

    /**********************************************
     * @brief Use normal distribution to generate a random card
     *
     * @return Card
     ***********************************************/
    static Card generateRandomCard();

    Card &operator=(const Card &to_copy);

    friend std::ostream &operator<<(std::ostream &output, const Card &c);
};

#endif // CARD_HXX