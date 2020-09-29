#include "server.h"

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

void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    QStringList test;
    QString hello = "hello client";

    test = getTest();

    out.setVersion(QDataStream::Qt_4_0);

    out << test;

//    socket->write("hello client\r\n");
    socket->write(block);
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}

QStringList Server::getTest()
{
    QStringList test;


    int graph[VERTEX][VERTEX] = { {0, 5, INFINITE, 10},
                            {INFINITE, 0, 3, INFINITE},
                            {INFINITE, INFINITE, 0, 1},
                            {INFINITE, INFINITE, INFINITE, 0}
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



