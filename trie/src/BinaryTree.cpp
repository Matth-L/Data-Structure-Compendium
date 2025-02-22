#include "BinaryTree.hpp"

void BinaryTree::Add(T data)
{
    std::shared_ptr<Node> current = root;
    while (current != nullptr)
    if (func(current->Left, data)) current 
}