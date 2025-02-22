#include "Dictionnaire.hpp"

using namespace std; 

void Dictionnaire::AddWord(string word)
{
    cerr << word << endl; 
    if (root == nullptr) 
    {
        root = std::make_shared<Node>(word[0]);
        std::shared_ptr<Node> current = root;
        for (size_t i = 1; i < word.size(); ++i) 
        {
            current->Left = std::make_shared<Node>(word[i]);
            current = current->Left;
        }
        return;
    }

    std::shared_ptr<Node> current = root;
    auto itWord = word.begin();

    while (itWord != word.end())
    {
        if (current->Data == *itWord) 
        {
            if (current->Left == nullptr) 
            {
                current->Left = std::make_shared<Node>(*(itWord+1));
            }
            current = current->Left;
            ++itWord;
        } 
        else
        {
            if (current->Right == nullptr) 
            {
                current->Right = std::make_shared<Node>(*itWord);
            }
            current = current->Right;
        }
    }
}

void Dictionnaire::DeleteWord(std::string word) {
    // if (root == nullptr) return; // Le dictionnaire est vide, rien à supprimer

    // std::shared_ptr<Node> current = root;
    // std::shared_ptr<Node> parent = nullptr;
    // bool isLeftChild = true;

    // for (char ch : word) {
    //     if (current == nullptr) 
    //     {
    //         return; // Le mot n'existe pas dans le dictionnaire
    //     }

    //     if (current->Data == ch) 
    //     {
    //         if (current->Right != nullptr) parent = current;
    //         current = current->Left;
    //     } 
    //     else 
    //     {
    //         current = current->Right;
    //         parent = current;
    //     }
    // }

    // if (current == nullptr) return; // Le mot n'existe pas dans le dictionnaire

    // if ()
}

bool Dictionnaire::SearchWord(string word)
{
    std::shared_ptr<Node> current = root;
    auto itWord = word.begin();

    bool res = false;
    while (itWord != word.end())
    {
        if (current->Data == *itWord) 
        {
            if (current->Left == nullptr) 
            {
                current->Left = std::make_shared<Node>(*(itWord+1));
            }
            current = current->Left;
            ++itWord;
        } 
        else
        {
            if (current->Right == nullptr) 
            {
                current->Right = std::make_shared<Node>(*itWord);
            }
            current = current->Right;
        }
    }
    return true;    
}

void Dictionnaire::PrintDico() {
    if (root != nullptr) {
        PrintDicoHelper(root, "", true);
    } else {
        std::cout << "The dictionary is empty." << std::endl;
    }
}

void Dictionnaire::PrintDicoHelper(std::shared_ptr<Node> node, const std::string& prefix, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "──>" : "--->" );
        std::cout << node->Data << std::endl;

        PrintDicoHelper(node->Left, prefix + (isLeft ? "│   " : "    "), true);
        PrintDicoHelper(node->Right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

