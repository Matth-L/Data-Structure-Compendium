#include "Card.hxx"
#include <iostream>
#include <random>

Card::Card()
    : value(0), bonus(0), color(Color::BLACK)
{
}

Card::Card(int value, int bonus, Color color)
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
    modifier = to_copy.modifier;
}

int Card::getValue() const
{
    return value;
}

int Card::getBonus() const
{
    return bonus;
}

Card::Color Card::getColor() const
{
    return color;
}

float Card::getModifier() const
{
    return modifier;
}

Card &Card::operator=(const Card &to_copy)
{
    value = to_copy.value;
    bonus = to_copy.bonus;
    color = to_copy.color;
    modifier = to_copy.modifier;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Card &c)
{
    output << "(" << c.value << ", " << c.bonus << ", ";
    output << (c.color == Card::Color::RED ? "RED" : "BLACK") << ")\n";
    output << "Modifier de p1: " << c.getModifier() << ".";
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

    int value = value_dist(gen);
    int bonus = bonus_dist(gen);
    Color color = color_dist(gen) == 0 ? Color::BLACK : Color::RED;

    // the modifier is set in the constructor
    return Card(value, bonus, color);
}