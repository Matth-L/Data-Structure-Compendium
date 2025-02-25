#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/**
 * @class Node
 * @brief A class representing a node in a doubly linked list with thread synchronization.
 * 
 * The Node class encapsulates the properties and behaviors of a node in a doubly linked list.
 * It includes thread synchronization mechanisms to safely access and modify the node's state.
 */
class Node
{
private:
    int node_id;
    Node *previous_node;
    Node *next_node;

    mutable mutex mutex_id; /**< Mutex for thread synchronization. */
    condition_variable cv;  /**< Condition variable to signal readiness. */
    bool ready;             /**< Flag indicating if the node is ready. */

public:
    /**
    * @brief Constructor to initialize a Node with a given ID.
    * 
    * @param id The unique identifier for the node.
    */
    Node(int id)
        : node_id(id),
          previous_node(nullptr),
          next_node(nullptr),
          ready(true) {}

    /**
    * @brief Sends the node ID when the node is ready.
    * 
    * This method waits until the node is ready and then returns the node ID.
    * 
    * @return int The node ID.
    */
    int send()
    {
        unique_lock<mutex> lock(mutex_id);
        cv.wait(lock, [this]
                { return isReady(); });
        return node_id;
    }

    // Getters
    int getID() const { return node_id; }
    Node *getPreviousNode() const { return previous_node; }
    Node *getNextNode() const { return next_node; }
    bool isReady() const { return ready; }

    // Setters
    void setPreviousNode(Node *node) { previous_node = node; }
    void setNextNode(Node *node) { next_node = node; }
    void setReady(bool state) { ready = state; }

    /**
    * @brief Sets the previous and next neighbors of the node.
    * 
    * @param p Pointer to the previous node.
    * @param n Pointer to the next node.
    */
    void set_neighbors(Node *p, Node *n)
    {
        setPreviousNode(p);
        setNextNode(n);
    }

    /**
    * @brief Checks if the node has a previous node.
    * 
    * @return bool True if the node has a previous node, false otherwise.
    */
    bool hasPreviousNode() const
    {
        return getPreviousNode() != nullptr;
    }

    /**
    * @brief Checks if the node has a next node.
    * 
    * @return bool True if the node has a next node, false otherwise.
    */
    bool hasNextNode() const
    {
        return getNextNode() != nullptr;
    }
};
