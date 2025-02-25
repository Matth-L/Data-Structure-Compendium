#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <omp.h>

#include "Thread.hpp"

using namespace std;

int main()
{
    const int num_nodes = 5;
    Node *nodes[num_nodes];

    // Step 1 : Create nodes and set neighbors.
    for (int i = 0; i < num_nodes; i++)
    {
        nodes[i] = new Node(i + 1);
    }
    // Set neighbors
    for (int i = 0; i < num_nodes; i++)
    {
        nodes[i]->set_neighbors(i > 0 ? nodes[i - 1] : nullptr,
                                i < num_nodes - 1 ? nodes[i + 1] : nullptr);
    }
    cout << "Nodes created and neighbors set" << endl;


    // Step 2 : Compute the total sum for each node in parallel.
    #pragma omp parallel for
    for (int i = 0; i < num_nodes; i++)
    {
        Thread thread(nodes[i]);
        thread.totaleSum();

    // Ensure thread-safe output
    #pragma omp critical
        {
            cout << "Total sum for node " << i + 1 << ": " << thread.getGlobalSum() << endl;
        }
    }

    // Step 2 : Clean up.
    for (int i = 0; i < num_nodes; i++)
    {
        delete nodes[i];
    }

    return 0;
}
