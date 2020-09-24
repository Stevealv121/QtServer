#include <QCoreApplication>
#include "server.h"
#include "graph.h"
#include "floydwarshall.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Graph::graphEdge edges[] = {{0,1,5},{0,2,3},{1,2,2},{1,4,3},{1,6,1},{2,3,7},{2,4,7}
//            ,{3,0,2},{2,5,6},{4,3,2},{4,5,1},{6,4,1}};
//    int vertices = 7;
//    int n_edges = sizeof(edges)/sizeof(edges[0]);

//    Graph graph(edges, n_edges, vertices);

//    qDebug()<<"Graph adjacency list ";
//    qDebug()<<"(start_vertex, end_vertex, weight):";
//    for(int i = 0; i<vertices; i++){
//        graph.printAdjList(graph.head[i], i);
//    }

    FloydWarshall algorithm;

    int graph[VERTEX][VERTEX] = { {0, 5, INFINITE, 10},
                        {INFINITE, 0, 3, INFINITE},
                        {INFINITE, INFINITE, 0, 1},
                        {INFINITE, INFINITE, INFINITE, 0}
    };

    algorithm.floydWarshall(graph);


    Server server;

    return a.exec();
}
