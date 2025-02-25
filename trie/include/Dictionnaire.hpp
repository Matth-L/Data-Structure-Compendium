#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP

#include <iostream>
#include <memory>

class Dictionnaire
{
    struct Node {
        char Data; 
        std::shared_ptr<Node> Left;
        std::shared_ptr<Node> Right;
        Node(char val) : Data(val), Left(nullptr), Right(nullptr) {}

        Node& operator=(const Node& other) 
        {
            if (this == &other) 
            {
                return *this;
            }

            Data = other.Data;

            Left = other.Left;
            Right = other.Right;

            return *this;
        }
    };

    public:
        Dictionnaire() : root(nullptr) {}

        void AddWord(const std::string& word);

        void DeleteWord(const std::string& word);

        bool SearchWord(std::string word);

        void PrintDico();

        void PrintDicoHelper(std::shared_ptr<Node> node, const std::string& prefix, bool isLeft);

        int Size();

        void ParcoursPreOrdre();

        void affichDict();

    private:
        void ParcoursPreOrdreHelper(std::shared_ptr<Node> node);

        bool SearchWordHelper(std::shared_ptr<Node> node, std::string::iterator it, std::string::iterator end);

        void affichDictHelper(std::shared_ptr<Node> node, std::string currentWord);

    private:
        std::shared_ptr<Node> root;
};
#endif