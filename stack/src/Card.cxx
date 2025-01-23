#include <iostream>
#include <random>
#include <cassert>

#include "Card.hxx"

/**********************************************
 * @brief Construct a new Card:: Card object
 *
 ***********************************************/
Card::Card()
    : data{0, 0, 0, 0}
{
}

/**********************************************
 * @brief Construct a new Card:: Card object
 *
 * @param value , la valeur de la carte, entre 0 et 10
 * @param bonus, la valeur du bonus, entre 0 et 4
 * @param color RED or BLACK
 * @throws assert si value ou bonus ne sont pas dans les bornes
 ***********************************************/
Card::Card(int value, int bonus, Color color)
{
    assert(value >= 0 && value <= 10);
    assert(bonus >= 0 && bonus <= 4);

    data.value = static_cast<unsigned int>(value);
    data.bonus = static_cast<unsigned int>(bonus);
    data.color = (color == Color::RED) ? 1 : 0;    // 1 = RED, 0 = BLACK
    data.modifier = (color == Color::RED) ? 1 : 0; // 1 = 1.5, 0 = 1.0
}

/**********************************************
 * @brief Construct a new Card:: Card object
 *
 * @param to_copy
 ***********************************************/
Card::Card(const Card &to_copy)
    : data(to_copy.data)
{
}
/**********************************************
 * @brief getteur de la valeur de la carte
 *
 * @return int
 ***********************************************/
int Card::getValue() const
{
    return data.value;
}

/**********************************************
 * @brief getter du bonus
 *
 * @return int
 ***********************************************/
int Card::getBonus() const
{
    return data.bonus;
}

/**********************************************
 * @brief getter du modificateur
 *
 * @return float
 ***********************************************/
float Card::getModifier() const
{
    return (data.modifier == 1) ? 1.5 : 1.0;
}

/**********************************************
 * @brief getter couleur
 *
 * @return Card::Color
 ***********************************************/
Card::Color Card::getColor() const
{
    return (data.color == 1) ? Color::RED : Color::BLACK;
}

/**********************************************
 * @brief calculateur du score
 *
 * @return float
 ***********************************************/
float Card::computeScore() const
{
    return data.value * getModifier() * data.bonus;
}

/**********************************************
 * @brief génération aléatoire
 *
 * @return Card
 ***********************************************/
Card Card::generateRandomCard()
{
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    std::random_device rd;
    std::mt19937 gen(rd());

    // uniform distribution
    std::uniform_int_distribution<> value_dist(1, 10);
    std::uniform_int_distribution<> bonus_dist(1, 4);
    std::uniform_int_distribution<> color_dist(0, 1);

    int value = value_dist(gen);
    int bonus = bonus_dist(gen);
    Color color = color_dist(gen) == 0 ? Color::BLACK : Color::RED;

    // the modifier is set in the constructor
    return Card(value, bonus, color);
}

/**********************************************
 * @brief surcharge =
 *
 * @param to_copy
 * @return Card&
 ***********************************************/
Card &Card::operator=(const Card &to_copy)
{
    data = to_copy.data;
    return *this;
}

/**********************************************
 * @brief surcharge <<
 *
 * @param output
 * @param c
 * @return std::ostream&
 ***********************************************/
std::ostream &operator<<(std::ostream &output, const Card &c)
{
    output << "(" << c.getValue()
           << ", " << c.getBonus()
           << ", ";
    if (c.getColor() == Card::Color::RED)
    {
        output << "RED";
    }
    else
    {
        output << "BLACK";
    }
    output << ") ; ";
    output << "Modifier de p1: " << c.getModifier() << " ; ";
    return output;
}