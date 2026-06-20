#include "Graph.h"

#include <QQueue>
#include <QSet>

Graph::Graph()
{
    addConnection("Gangnam", "Seolleung");
    addConnection("Seolleung", "Samseong");
    addConnection("Samseong", "Jamsil");
    addConnection("Gangnam", "Gyodae");
    addConnection("Gyodae", "Sadang");
}

void Graph::addConnection(QString station1, QString station2)
{
    adj[station1].append(station2);
    adj[station2].append(station1);
}

QString Graph::findPath(QString start, QString end)
{
    if (!adj.contains(start) || !adj.contains(end))
    {
        return "Station not found.";
    }

    QQueue<QString> queue;
    QSet<QString> visited;
    QMap<QString, QString> parent;

    queue.enqueue(start);
    visited.insert(start);

    while (!queue.isEmpty())
    {
        QString current = queue.dequeue();

        if (current == end)
            break;

        for (const QString& next : adj[current])
        {
            if (!visited.contains(next))
            {
                visited.insert(next);
                parent[next] = current;
                queue.enqueue(next);
            }
        }
    }

    if (!visited.contains(end))
    {
        return "No path found.";
    }

    QVector<QString> path;
    QString cur = end;

    while (cur != start)
    {
        path.prepend(cur);
        cur = parent[cur];
    }

    path.prepend(start);

    QString result;

    for (int i = 0; i < path.size(); i++)
    {
        result += path[i];

        if (i != path.size() - 1)
            result += " -> ";
    }

    return result;
}