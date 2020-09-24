#include "floydwarshall.h"

FloydWarshall::FloydWarshall()
{

}

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

void FloydWarshall::floydWarshall(int graph[][VERTEX])
{

    int matrix[VERTEX][VERTEX];
    int i, j, k;

    for (i = 0; i <VERTEX; i++){
        for (j=0; j<VERTEX; j++){
            matrix[i][j] = graph[i][j];
        }
    }


    for (k=0; k<VERTEX; k++){
        for (i=0; i<VERTEX; i++){
            for (j=0; j<VERTEX; j++){

                if (matrix[i][j] + matrix[i][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][j] + matrix[i][j];
                }
            }
        }
    }

    printMatrix(matrix);

}
