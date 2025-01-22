#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class Pile
{
private:
    // "smart-pointer" permettant de ne pas s'occupe de la suppression
    unique_ptr<T[]> tab;
    // indice de l'élément au sommet de la pile
    int ptrSommet;
    // sommet
    int tailleMax;
    static const int MAX_PILE = 100;

public:
    /**********************************************
     * @brief Constructeur de la pile
     *
     * @param max taille maximale de la pile
     * @throws std::invalid_argument si max <= 0
     * @throws std::bad_alloc si l'allocation de mémoire échoue
     ***********************************************/
    Pile(int max)
        : tab(make_unique<T[]>(max)),
          ptrSommet(-1),
          tailleMax(max)
    {
        if (max <= 0 || max > MAX_PILE)
        {
            throw invalid_argument("Pile, taille non autorisé");
        }
    }

    /**********************************************
     * @brief Constructeur de copie
     *
     * @param to_copy la pile à copier
     * @throws les erreurs de make_unique si l'allocation de mémoire échoue
     ***********************************************/
    Pile(const Pile &to_copy)
        : tab(make_unique<T[]>(to_copy.tailleMax)),
          ptrSommet(to_copy.ptrSommet),
          tailleMax(to_copy.tailleMax)
    {
        for (int i = 0; i <= ptrSommet; ++i)
        {
            tab[i] = to_copy.tab[i];
        }
    }

    /**********************************************
     * @brief Destructeur de la pile
     *
     ***********************************************/
    ~Pile() = default;

    /**********************************************
     * @brief Empile un élément dans la pile de type T
     *
     ***********************************************/
    void empiler(const T &element)
    {
        if (ptrSommet + 1 >= tailleMax)
        {
            throw length_error("Empiler : la pile est pleine!");
        }

        tab[++ptrSommet] = element;
    }

    /**********************************************
     * @brief Dépile un élément de type T de la pile
     *
     * @return T, l'élément dépilé
     ***********************************************/
    T depiler()
    {
        if (estVide())
        {
            throw logic_error("Dépiler : la pile est vide!");
        }

        return tab[ptrSommet--];
    }

    /**********************************************
     * @brief Vérifie si la pile est vide
     *
     * @return true si la pile est vide, false sinon
     ***********************************************/
    bool estVide() const
    {
        return ptrSommet == -1;
    }

    /**********************************************
     * @brief Retourne la taille de la pile
     *
     * @return int la taille de la pile
     ***********************************************/
    int taille() const
    {
        return ptrSommet + 1;
    }
    /**********************************************
     * @brief Retourne l'élément au sommet de la pile
     *
     * @return const T&
     * @throws logic_error, s'il n'y a rien dans la pile
     ***********************************************/
    const T &sommet() const
    {
        if (estVide())
        {
            throw logic_error("sommet() : il n'y a rien dans la pile");
        }
        return tab[ptrSommet];
    }

    /**********************************************
     * @brief Surcharge de l'opérateur =
     *
     * @param p ,la pile à copier
     * @return Une référence à la pile courante
     ***********************************************/
    Pile<T> &operator=(Pile<T> p)
    {
        if (this == &p)
        {
            return *this;
        }

        Pile<T> tmp(p);
        swap(tab, tmp.tab);
        swap(ptrSommet, tmp.ptrSommet);
        swap(tailleMax, tmp.tailleMax);

        return *this;
    }

    /**********************************************
     * @brief Surcharge de l'opérateur <<
     *
     * @tparam U
     * @return std::ostream&
     ***********************************************/
    template <typename U>
    friend std::ostream &operator<<(std::ostream &output, const Pile<U> &p)
    {
        output << "[";
        for (int i = 0; i <= p.ptrSommet; ++i)
        {
            output << p.tab[i];
            if (i < p.ptrSommet)
            {
                output << ", ";
            }
        }
        output << "].";
        return output;
    }
};

#endif // PILE_H
