#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Node {
public:
    int node_id;
    Node* prev;
    Node* next;
    int sum;
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;

    Node(int id) : node_id(id), prev(nullptr), next(nullptr), sum(id) {}

    void set_neighbors(Node* p, Node* n) {
        prev = p;
        next = n;
    }

    void send(int value, Node* sender) {
        std::unique_lock<std::mutex> lock(mtx);
        sum += value;
        ready = true;
        cv.notify_one();

        if (sender == prev && next) {
            next->send(sum, this);
        } else if (sender == next && prev) {
            prev->send(sum, this);
        }
    }

    void compute_sum() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return ready; });
        std::cout << "Node " << node_id << " final sum: " << sum << std::endl;
    }
};

int main() {
    const int num_nodes = 5;
    Node* nodes[num_nodes];

    // Création des nœuds
    for (int i = 0; i < num_nodes; ++i) {
        nodes[i] = new Node(i + 1);
    }

    // Configuration des voisins
    for (int i = 0; i < num_nodes; ++i) {
        nodes[i]->set_neighbors(i > 0 ? nodes[i - 1] : nullptr,
                                i < num_nodes - 1 ? nodes[i + 1] : nullptr);
    }

    // Lancement des threads
    std::thread threads[num_nodes];
    for (int i = 0; i < num_nodes; ++i) {
        threads[i] = std::thread(&Node::compute_sum, nodes[i]);
    }

    // Démarrage de la propagation
    nodes[0]->send(nodes[0]->node_id, nullptr);

    // Attente de la fin des threads
    for (int i = 0; i < num_nodes; ++i) {
        threads[i].join();
        delete nodes[i];
    }

    return 0;
}
