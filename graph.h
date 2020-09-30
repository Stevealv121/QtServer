#ifndef GRAPH_H
#define GRAPH_H

#include <QDebug>


/**
 * Implementacion de un grafo utlizando una lista adyacente
 */
class Graph {

public:
    /**
     * Node structure
     */
    struct adjNode{
        int val, cost;
        adjNode* next;
    };

    /**
     * Obtiene adjacency list node
     * @param value of vertex
     * @param weight of edge
     * @param head node
     * @return adjacency list node
     */
    adjNode* getAdjListNode(int value, int weight, adjNode* head);
    /**
     * Edge structure
     */
    struct graphEdge{

        int start, end, weight;
    };

    adjNode **head; /**< TODO: describe */

    /**
     * @brief Constructor
     *
     * @param edges[] Aristas
     * @param n numero de aristas
     * @param N numero de vertices
     */
    Graph(graphEdge edges[], int n, int N);
    /**
     * @brief Destructor
     *
     */
    ~Graph();
    /**
     * Print graph: edges representation
     * @param ptr node
     * @param i index
     */
    void printAdjList(adjNode* ptr, int i);

private:
/**
 * number of nodes in the graph
 */
    int N;

};

#endif // GRAPH_H
