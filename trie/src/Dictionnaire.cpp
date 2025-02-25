#include "Dictionnaire.hpp"
#include <algorithm>

using namespace std; 

void Dictionnaire::AddWord(const std::string& word)
{
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

    while (itWord != word.end()-1)
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

void Dictionnaire::DeleteWord(const std::string& word) 
{
    if (root == nullptr) 
    {
        return; // Le dictionnaire est vide, rien à supprimer.
    }

    std::shared_ptr<Node> current = root;
    std::shared_ptr<Node> parent = root;
    size_t index = 0;
    bool turnLeft = false;

    // Trouver le nœud correspondant au dernier caractère du mot
    while (index < word.size() && current != nullptr) 
    {
        if (current->Data == word[index]) 
        {
            if (current->Left !=nullptr && current->Left->Right != nullptr)
            {
                turnLeft = true;
                parent = current;
            }
            current = current->Left;
            ++index;
        } 
        else 
        {
            parent = current;
            current = current->Right;
            turnLeft = false;
        }
    }
    
    // Si le mot n'a pas été trouvé, ne rien faire
    if (index != word.size() || current != nullptr) 
    {
        return;
    }

    // Maintenant, nous devons supprimer le mot
    if (turnLeft) 
    {
        //si le dico ne contient qu'une lettre
        if (parent->Left == nullptr) 
        {
            root = nullptr;
            return;
        }
        parent->Left = parent->Left->Right;

        //pour supprimer la dernière lettre si un mot se situe à droite 
        if (parent->Left == nullptr) parent = parent->Right;
    }
    else 
    {
        parent->Right = parent->Right->Right;
    }
}

bool Dictionnaire::SearchWord(std::string word) {
    if (root == nullptr) {
        return false; // L'arbre est vide
    }
    return SearchWordHelper(root, word.begin(), word.end());
}

bool Dictionnaire::SearchWordHelper(std::shared_ptr<Node> node, std::string::iterator it, std::string::iterator end) {
    if (it == end) {
        return true; // Tous les caractères du mot ont été trouvés
    }

    if (node == nullptr) {
        return false; // Fin de l'arbre atteinte sans trouver le mot
    }

    if (node->Data == *it) {
        // Le caractère courant correspond, on passe au caractère suivant dans le mot et dans l'arbre
        return SearchWordHelper(node->Left, it + 1, end);
    } else {
        // Le caractère ne correspond pas, on cherche dans le sous-arbre droit
        return SearchWordHelper(node->Right, it, end);
    }
}

void Dictionnaire::affichDict() {
    affichDictHelper(root, "");
    cout << endl;
}

void Dictionnaire::affichDictHelper(std::shared_ptr<Node> node, std::string currentWord) {
    if (node == nullptr) {
        return;
    }

    // Parcours infixe : gauche -> nœud courant -> droite
    affichDictHelper(node->Right, currentWord);

    // Ajouter le caractère du nœud courant au mot en cours de construction
    currentWord = node->Data + currentWord;

    // Si on est à la fin d'un mot (nœud sans enfant gauche), on affiche le mot
    if (node->Left == nullptr) {
        std::reverse(currentWord.begin(), currentWord.end());
        std::cout << currentWord << std::endl;
    }

    affichDictHelper(node->Left, currentWord);
}

void Dictionnaire::PrintDico() {
    if (root != nullptr) {
        PrintDicoHelper(root, "", true);
    } else {
        std::cout << "The dictionary is empty." << std::endl;
    }
}

void Dictionnaire::PrintDicoHelper(std::shared_ptr<Node> node, const std::string& prefix, bool isLeft) {
    if (node != nullptr ) {
        if (node->Data == '\0') return;
        std::cout << prefix;
        std::cout << (isLeft ? "──>" : "-->" );
        std::cout << node->Data << std::endl;

        PrintDicoHelper(node->Left, prefix + (isLeft ? "|  " : "    "), true);
        PrintDicoHelper(node->Right, prefix + (isLeft ? "" : "    "), false);
    }
}

