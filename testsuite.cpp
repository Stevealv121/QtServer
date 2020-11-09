#include "testsuite.h"
#include <QSignalSpy>

TestSuite::TestSuite()
{
    int graph1[VERTEX][VERTEX] = { {0, 8, INFINITE, INFINITE,12},
                            {INFINITE, 0, 3, INFINITE,INFINITE},
                            {INFINITE, INFINITE, 0, 5,INFINITE},
                            {INFINITE, INFINITE, INFINITE, 0,5},
                            {INFINITE, INFINITE, INFINITE, INFINITE,0}
        };

    int i, j;

    for (i = 0; i <VERTEX; i++){
        for (j=0; j<VERTEX; j++){
            graph[i][j] = graph1[i][j];
        }
    }

}

void TestSuite::testGraph()
{

}

void TestSuite::testPrint()
{

    bool flag = floydWarshall.printMatrix(graph);

    QCOMPARE(true,flag);
}

void TestSuite::testFloydWarshall()
{
    int result[VERTEX][VERTEX] = {{0,8,11,16,12},
                                  {INFINITE,0,3,8,13},
                                  {INFINITE,INFINITE,0,5,10},
                                  {INFINITE,INFINITE,INFINITE,0,5},
                                  {INFINITE,INFINITE,INFINITE,INFINITE,0}};

    floydWarshall.floydWarshall(graph);

    int i, j;

    for (i = 0; i <VERTEX; i++){
        for (j=0; j<VERTEX; j++){
            QCOMPARE(floydWarshall.matrix[i][j],result[i][j]);
        }
    }
}

void TestSuite::testNewConnection()
{
    //bool flag = server->newConnection();
    QSignalSpy spy(server,SIGNAL(ok()));
    while (spy.count()==0)
        QTest::qWait(5000);


    //QCOMPARE(true,flag);
}

QTEST_MAIN(TestSuite)
