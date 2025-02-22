#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <memory>
#include "Node.hpp"

void threadFunction(Node *node)
{
    node->computeSum();
}

using namespace std;

int main()
{
    std::vector<std::unique_ptr<Node>> list_node;
    size_t size = 100;

    // Getting the seed for the rng
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<> break_dist(1, 10);

    // Create the first node
    int id = break_dist(rng);
    list_node.push_back(std::make_unique<Node>(id));

    // Create the rest of the nodes
    for (size_t i = 1; i < size; ++i)
    {
        int id = break_dist(rng);
        auto new_node = std::make_unique<Node>(id);

        // Link the new node with the previous node
        Node &previous_node = *list_node.back();
        previous_node.setNext(new_node.get());
        new_node->setPrev(&previous_node);

        // Add the new node to the vector
        list_node.push_back(std::move(new_node));
    }

    // Create threads for each node
    std::vector<std::thread> list_thread;
    for (auto &node : list_node)
    {
        list_thread.emplace_back(threadFunction, node.get());
    }

    // Join threads
    for (std::thread &t : list_thread)
    {
        t.join();
    }

    // Output the sum from any node (should be the same)
    cout << "Sum of all node IDs: " << list_node.back()->receive() << endl;

    return 0;
}
