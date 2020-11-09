#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "floydwarshall.h"
#include "graph.h"
#include "server.h"

#include <QObject>
#include <QTest>

class TestSuite: public QObject
{
    Q_OBJECT
public:
    TestSuite();

private slots:

    void testGraph();
    void testPrint();
    void testFloydWarshall();
    void testNewConnection();

private:
    FloydWarshall floydWarshall;
    Server *server;
    int graph[VERTEX][VERTEX];
};

#endif // TESTSUITE_H
