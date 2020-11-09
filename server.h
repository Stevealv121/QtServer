#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include "floydwarshall.h"

/**
 * @brief Servidor el cual almacena el algoritmo de Floyd-Warshall y
 * permite conectarse al cliente mediante socket
 *
 */
class Server : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor del Server
     *
     * @param parent
     */
    explicit Server(QObject *parent = 0);

signals:
    void ok();

public slots:
    /**
     * @brief SLOT encargada de la nueva conexion
     *
     */
    bool newConnection();
    /**
     * @brief Genera una lista con el resultado del algortimo
     *
     * @return QStringList resutado del algoritmo
     */
    QStringList getTest();

private:
    QTcpServer *server; /**< server */
};

#endif // SERVER_H
