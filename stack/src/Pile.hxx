#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Pile
{
private:
    T *elements;
    int max_elements;
    int taille_pile;

public:
    /**********************************************
     * @brief
     *
     * @param max
     ***********************************************/
    Pile(int max);

    /**********************************************
     * @brief
     *
     ***********************************************/
    Pile(const Pile &);

    /**********************************************
     * @brief
     *
     ***********************************************/
    ~Pile();

    /**********************************************
     * @brief
     *
     ***********************************************/
    void empiler(const T &);

    /**********************************************
     * @brief
     *
     * @return T
     ***********************************************/
    T depiler();

    /**********************************************
     * @brief
     *
     * @return true
     * @return false
     ***********************************************/
    bool estVide() const;

    /**********************************************
     * @brief
     *
     * @return int
     ***********************************************/
    int taille() const;

    /**********************************************
     * @brief
     *
     * @return const T&
     ***********************************************/
    const T &sommet() const;

    /**********************************************
     * @brief
     *
     * @return const Pile<T>&
     ***********************************************/
    const Pile<T> &operator=(const Pile<T> &);

    /**********************************************
     * @brief
     *
     * @tparam U
     * @return std::ostream&
     ***********************************************/
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Pile<U> &);
};

template <typename T>
Pile<T>::Pile(int max) : max_elements(max), taille_pile(0)
{
    elements = new T[max_elements];
}

template <typename T>
Pile<T>::Pile(const Pile<T> &to_copy)
    : max_elements(to_copy.max_elements),
      taille_pile(to_copy.taille_pile)
{
    elements = new T[max_elements];
    std::copy(to_copy.elements, to_copy.elements + taille_pile, elements);
}

template <typename T>
Pile<T>::~Pile()
{
    delete[] elements;
}

#endif // PILE_H
