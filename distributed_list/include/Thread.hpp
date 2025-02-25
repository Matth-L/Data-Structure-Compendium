#include "Node.hpp"

/**
 * @class Thread
 * @brief A class to represent a thread that calculates the sum of nodes in a linked structure.
 *
 * The Thread class provides methods to calculate the sum of values from nodes
 * in both left and right directions starting from a given node. It maintains
 * a global sum which is updated by summing values from both directions.
 */
class Thread
{
private:
    int globalSum = 0; /**< The global sum of node values. */
    Node *startNode;   /**< The starting node for sum calculations. */

public:
    Thread() : startNode(nullptr) {}

    /**
     * @brief Parameterized constructor initializing startNode to the given node.
     * @param sNode Pointer to the starting node.
     */
    Thread(Node *sNode) : startNode(sNode) {}

    /**
     * @brief Get the global sum of node values.
     * @return The global sum.
     */
    int getGlobalSum() const { return globalSum; }

    /**
     * @brief Recursively calculate the sum of node values to the left of the given node.
     * @param a Pointer to the current node.
     * @return The sum of node values to the left.
     */
    int sum_Left(Node *a)
    {

        if (a->hasPreviousNode())
        {
            return a->send() + sum_Left(a->getPreviousNode());
        }
        else
        {
            return a->send();
        }
    }

    /**
     * @brief Recursively calculate the sum of node values to the right of the given node.
     * @param a Pointer to the current node.
     * @return The sum of node values to the right.
     */
    int sum_Right(Node *a)
    {
        if (a->hasNextNode())
        {
            return a->send() + sum_Right(a->getNextNode());
        }
        else
        {
            return a->send();
        }
    }

    /**
     * @brief Calculate the total sum of node values in both directions and update the global sum.
     */
    void totaleSum()
    {
        globalSum += sum_Left(startNode);
        globalSum += sum_Right(startNode);
        globalSum -= startNode->getID();
    }
};
