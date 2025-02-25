#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Node.hpp"

int main()
{
    const int num_nodes = 5;
    Node *nodes[num_nodes];

    // Création des nœuds
    for (int i = 0; i < num_nodes; ++i)
    {
        nodes[i] = new Node(i + 1);
    }

    // Configuration des voisins
    for (int i = 0; i < num_nodes; ++i)
    {
        nodes[i]->set_neighbors(i > 0 ? nodes[i - 1] : nullptr,
                                i < num_nodes - 1 ? nodes[i + 1] : nullptr);
    }

    // Lancement des threads
    thread threads[num_nodes];
    for (int i = 0; i < num_nodes; ++i)
    {
        threads[i] = thread(&Node::compute_sum, nodes[i]);
    }

    // Démarrage de la propagation
    nodes[3]->start_propagation();
    for (int i = 0; i < num_nodes; ++i)
    {
        cout << nodes[i]->getGlobalSum() << endl;
    }

    // Attente de la fin des threads
    for (int i = 0; i < num_nodes; ++i)
    {
        threads[i].join();
        delete nodes[i];
    }

    return 0;
}
