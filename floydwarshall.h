#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "graph.h"

#define VERTEX 5
#define INFINITE 99999


class FloydWarshall
{
public:
    FloydWarshall();

    void printMatrix(int matrix[][VERTEX]);

    void floydWarshall(int graph[][VERTEX]);

    int matrix[VERTEX][VERTEX];


private:




};

#endif // FLOYDWARSHALL_H
