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
        fflush(stdout);
    }
};