#include "graph.h"

/**
 * @brief Inserta newNodes en la lista adyacente del
 * grafo dado, apunta newNode hacia el actual head
 *
 * @param value Valor del vertice que se dirige
 * @param weight Peso de la arista entre vertices
 * @param head Vertice head
 * @return Graph::adjNode
 */
Graph::adjNode *Graph::getAdjListNode(int value, int weight, Graph::adjNode *head) {

    adjNode* newNode = new adjNode;
    newNode->val = value;
    newNode->cost = weight;

    newNode->next = head;
    return newNode;

}

/**
 * @brief Constructor de la clase
 * Asigna memoria para un nuevo nodo.
 * Inicializa puntero head para todos los vertices
 * Construye grafo dirigido agregandole aristas
 * Inserta newNode al principio
 * Apunta el puntero head a newNode
 *
 * @param edges Array de aristas del grafo
 * @param n Numero de aristas
 * @param N Numero de verties en el grafo
 */
Graph::Graph(Graph::graphEdge *edges, int n, int N) {


    head = new adjNode*[N]();
    this->N = N;

    for (int i = 0; i < N; ++i)
        head[i] = nullptr;

    for (int i = 0; i < n; i++)  {
        int start_ver = edges[i].start;
        int end_ver = edges[i].end;
        int weight = edges[i].weight;

        adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);


        head[start_ver] = newNode;
    }

}

/**
 * @brief Destructor de Graph: Libera espacio
 *
 */
Graph::~Graph() {

    for (int i = 0; i < N; i++) {
        delete[] head[i];
        delete[] head;
    }

}

/**
 * @brief Imprime todos los vertices adyacentes del vertice dado
 *
 * @param ptr puntero head
 * @param i vertice
 */
void Graph::printAdjList(Graph::adjNode *ptr, int i) {

    while (ptr != nullptr) {

        qDebug()<<"("<<i<<","<< ptr->val<< ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }

}
