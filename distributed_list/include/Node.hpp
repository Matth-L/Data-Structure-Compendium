/**********************************************
 * @file Node.hpp
 * @brief File that allows to compute double linked list in each thread
 * @link https://cplusplus.com/reference/thread/thread/
 ***********************************************/

#include <mutex>
#include <iostream>
#include <condition_variable>

using namespace std;

class Node
{
private:
    const int id;
    Node *prev;
    Node *next;
    int sum;
    mutex mutex_sum;
    condition_variable cv;
    bool ready;

public:
    Node(int id) : id(id), prev(nullptr), next(nullptr), sum(0), ready(false) {}

    /**********************************************
     * @brief Set the Next object
     * @param next
     ***********************************************/
    void setNext(Node *next)
    {
        this->next = next;
    }

    /**********************************************
     * @brief Set the Prev object
     * @param prev
     ***********************************************/
    void setPrev(Node *prev)
    {
        this->prev = prev;
    }

    /**********************************************
     * @brief
     * @param value
     ***********************************************/
    void send(int value)
    {
        // We lock the sum variable
        unique_lock<mutex> lock(mutex_sum);

        sum += value;
        ready = true; // We got the sum value, release the mutex

        // Unblocks all threads currently waiting for this condition.
        // https://cplusplus.com/reference/condition_variable/condition_variable/notify_all/
        cv.notify_all();
    }

    int receive()
    {
        unique_lock<mutex> lock(mutex_sum);

        // wait causes the current thread to block until the condition
        // variable is notified
        // https://en.cppreference.com/w/cpp/thread/condition_variable/wait
        cv.wait(lock,
                [this]
                { return ready; });

        ready = false; // locking the mutex, it will be released when sending
        return sum;
    }

    /**********************************************
     * @brief Computes the sum across the nodes
     *
     * Calculates the sum of node IDs in a double-linked list.
     * Communicates with the next and previous nodes.
     ***********************************************/
    void computeSum()
    {
        if (next)
        {
            next->send(id);
            sum = next->receive();
        }
        else
        {
            sum = id;
        }

        if (prev)
        {
            int prevSum = prev->receive();
            sum += prevSum;
            prev->send(sum);
        }
    }
};