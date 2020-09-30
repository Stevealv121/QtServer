#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "graph.h"

#define VERTEX 5
#define INFINITE 99999


/**
 * @brief Implementacion Algoritmo Floyd-Warshall
 *
 */
class FloydWarshall
{
public:
    /**
     * @brief Constructor
     *
     */
    FloydWarshall();

    /**
     * @brief Imprime el resultado del algoritmo
     *
     * @param matrix[][]
     */
    void printMatrix(int matrix[][VERTEX]);

    /**
     * @brief Genera la solucion del algortimo
     *
     * @param graph[][] grafo a resolver
     */
    void floydWarshall(int graph[][VERTEX]);

    int matrix[VERTEX][VERTEX]; /**< Almacena solucion del algortimo */


private:




};

#endif // FLOYDWARSHALL_H
