#include "server.h"

/**
 * @brief Constructor de la clase Server
 * Crea un nuevo QTcpServer.
 * Genera un signal y slot para la nueva conexion.
 * Se asegura de que el servidor este escuchando, en otras palabras que se haya iniciado.
 *
 * @param parent
 */
Server::Server(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";

    }
}

/**
 * @brief Crea un socket para la conexion
 * Envia la lista que contiene las distancia mas corta entre cada par de vertices,
 * esta lista es codificada en QByteArray utilizando QDataStream y luego es escrita
 * al socket. Primero se crea los objetos QByteArray y QDataStream, pasando el QByteArray
 * al constructor de QDataStream, despues se establece la version Qt_4_0 para asegurarnos
 * la comunicacion con el cliente.
 *
 */
bool Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    QStringList test;

    test = getTest();

    out.setVersion(QDataStream::Qt_4_0);

    out << test;

    socket->write(block);
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
    emit ok();
    return true;
}

/**
 * @brief Encargado de generar el grafo, y hacer la prueba
 * del algoritmo Floyd-Warshall. Almacena el resultado de la
 * prueba en una QStringList.
 *
 * @return QStringList que contiene el resultado de la prueba del algoritmo
 */
QStringList Server::getTest()
{
    QStringList test;


    int graph[VERTEX][VERTEX] = { {0, 8, INFINITE, INFINITE,12},
                            {INFINITE, 0, 3, INFINITE,INFINITE},
                            {INFINITE, INFINITE, 0, 5,INFINITE},
                            {INFINITE, INFINITE, INFINITE, 0,5},
                            {INFINITE, INFINITE, INFINITE, INFINITE,0}
        };

    FloydWarshall algorithm;
    algorithm.floydWarshall(graph);


    for (int i = 0; i <VERTEX; i++){
        for (int j = 0; j <VERTEX; j++){

            test << QString::number(algorithm.matrix[i][j]);
        }
    }

    return test;
}



