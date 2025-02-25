#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Node
{
private:
    int node_id;
    int sum;
    int global_sum;

public:
    Node *previous_node;
    Node *next_node;
    mutex mutex_sum;
    condition_variable cv;
    bool ready = false;

    Node(int id) : node_id(id), previous_node(nullptr), next_node(nullptr), sum(0) {}

    int getID() { return node_id; }
    int getSum() { return sum; }
    int getGlobalSum() { return global_sum; }

    void set_neighbors(Node *p, Node *n)
    {
        previous_node = p;
        next_node = n;
    }

    void start_propagation()
    {
        if (previous_node)
        {
            previous_node->start_propagation();
        }
        else
        {
            send(node_id, this);
        }
    }

    void send_final_sum(int value)
    {
        global_sum = value;
        if (previous_node)
        {
            previous_node->send_final_sum(value);
        }
    }
    void send(int value, Node *sender)
    {
        unique_lock<mutex> lock(mutex_sum);
        sum += value; // Accumulate the sum

        ready = true;
        cv.notify_one();

        if (next_node)
        {
            next_node->send(sum + next_node->getID(), this);
        }
        else
        { // last one should have the final value
            global_sum = sum;
            send_final_sum(global_sum);
        }
    }

    void compute_sum()
    {
        unique_lock<mutex> lock(mutex_sum);
        cv.wait(lock, [this]
                { return ready; });
    }
};
