#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class File
{
private: // ...Modèle d'implantation
    std::vector<T> data;
    int front;
    int back;
    int count;

public: // constructeurs et destructeurs:
    File() : data(), front(0), back(0), count(0) {}
    File(const File &other) : data(other.data), front(other.front), back(other.back), count(other.count) {}
    ~File() {}

    // modificateurs
    void enfiler(const T& value) {
        data.push_back(value);
        back = (back + 1) % data.capacity();
        count++;
    }

    T defiler() {
        if (estVide()) {
            throw std::underflow_error("Queue is empty");
        }
        T value = data[front];
        front = (front + 1) % data.capacity();
        count--;
        return value;
    }

    // sélecteurs
    int taille() const {
        return count;
    }

    bool estVide() const {
        return count == 0;
    }

    const T& premier() const {
        if (estVide()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }

    const T& dernier() const {
        if (estVide()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[(back - 1 + data.capacity()) % data.capacity()];
    }

    // surcharges d'opérateurs
    const File<T>& operator = (const File<T>& other) {
        if (this != &other) {
            data = other.data;
            front = other.front;
            back = other.back;
            count = other.count;
        }
        return *this;
    }

    template <typename U> 
    friend std::ostream& operator << (std::ostream& os, const File<U>& q) {
        for (int i = 0; i < q.count; ++i) {
            os << q.data[(q.front + i) % q.data.capacity()] << " ";
        }
        return os;
    }
};

#endif


