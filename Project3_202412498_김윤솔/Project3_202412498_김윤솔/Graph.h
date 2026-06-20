#pragma once

#include <QString>
#include <QMap>
#include <QVector>

class Graph
{
public:
    Graph();

    void addConnection(QString station1, QString station2);
    QString findPath(QString start, QString end);

private:
    QMap<QString, QVector<QString>> adj;
};