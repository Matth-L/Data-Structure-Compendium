#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

template <typename T>
 
using FunctionType = bool (*)(T);

template <typename T, FunctionType<T> func>
class BinaryTree
{
    struct Node {
        T Data; 
        std::shared_ptr<Node> Left;
        std::shared_ptr<Node> Right;
        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    public:
        BinaryTree() : root(nullptr) {}

        void Add(T Data);

        void DeleteNode(T value)

        bool Search(T value)

        int Size();

    private:
        std::shared_ptr<Node> root;
}

#endif