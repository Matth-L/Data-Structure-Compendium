#include "include/Card.hxx"
#include <iostream>
#include <random>

Card::Card()
    : value(0), bonus(0), color(Color::BLACK)
{
}

Card::Card(unsigned char value, unsigned char bonus, Color color)
    : value(value), bonus(bonus), color(color)
{
    if (color == Color::RED)
    {
        modifier = 1.5f;
    }
    else
    {
        modifier = 1.0f;
    }
}

Card::Card(const Card &to_copy)
    : value(to_copy.value), bonus(to_copy.bonus), color(to_copy.color)
{
}

unsigned char Card::getValue() const
{
    return value;
}

unsigned char Card::getBonus() const
{
    return bonus;
}

Card::Color Card::getColor() const
{
    return color;
}

Card &Card::operator=(const Card &to_copy)
{
    value = to_copy.value;
    bonus = to_copy.bonus;
    color = to_copy.color;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Card &c)
{
    output << "(" << c.value << ", " << c.bonus << ", ";
    output << (c.color == Card::Color::RED ? "RED" : "BLACK") << ")";
    return output;
}

float Card::computeScore() const
{
    return value * modifier * bonus;
}

Card Card::generateRandomCard()
{
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    std::random_device rd;
    std::mt19937 gen(rd());

    // uniform distribution
    std::uniform_int_distribution<> value_dist(1, 10);
    std::uniform_int_distribution<> bonus_dist(1, 4);
    std::uniform_int_distribution<> color_dist(0, 1);

    unsigned char value = value_dist(gen);
    unsigned char bonus = bonus_dist(gen);
    Color color = color_dist(gen) == 0 ? Color::BLACK : Color::RED;

    // the modifier is set in the constructor
    return Card(value, bonus, color);
}