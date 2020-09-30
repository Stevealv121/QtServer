#include "floydwarshall.h"

/**
 * @brief Constructor
 *
 */
FloydWarshall::FloydWarshall()
{

}

/**
 * @brief Imprime un array 2D, que en este caso representa
 * un array con el resultado del algoritmo aplicado
 *
 * @param matrix[][] 2D Array representacion del grafo
 */
void FloydWarshall::printMatrix(int matrix[][VERTEX])
{
    qDebug()<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < VERTEX; i++)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            if (matrix[i][j] == INFINITE)
                qDebug()<<"INF"<<"     ";
            else
                qDebug()<<matrix[i][j]<<"     ";
        }
     qDebug()<<"";
    }
}

/**
 * @brief Soluciona el camino mas corto de todos los pares,
 * utilizando el algortimo FLoyd-Warshall
 * Inicializa la solucion por obtener los datos del graph y
 * guardarlos en matrix. Luego agrega todos los vertices,
 * uno por uno, al conjunto de vertices intermedios.
 * Antes de empezar la iteracion, tenemos todas las distancias
 * mas cortas entre pares de vertices tal que la distancia
 * mas corta considere solo los vertices del conjunto
 * {0,1,2,...,k-1} como vertices intermedios . Despues del
 * final de la iteracion, el vertice k es agregado al conjunto
 * de vertices intermedios y el conjunto se convierte en
 * {0,1,2,...,k}. Entonces se eligen todos los vertices origen
 * uno por uno, luego se escogen todos los vertices como destinacion
 * de los vertices origen elegidos y si el vertice k esta en la ruta
 * mas corta entre i y j, entonces se actualiza el valor en matrix[i][j]
 * Por ultimo se imprime la solucion del algoritmo.
 *
 * @param graph[][]
 */
void FloydWarshall::floydWarshall(int graph[][VERTEX])
{

    int i, j, k;

    for (i = 0; i <VERTEX; i++){
        for (j=0; j<VERTEX; j++){
            matrix[i][j] = graph[i][j];
        }
    }


    for (k=0; k<VERTEX; k++){
        for (i=0; i<VERTEX; i++){
            for (j=0; j<VERTEX; j++){

                if (matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    printMatrix(matrix);

}

