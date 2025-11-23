#include "BellmanFord.h"

Graph::Graph(int v) : vertices(v) {}

void Graph::addEdge(int u, int v, double w)
{
    edges.emplace_back(u, v, w);
}

bool Graph::BellmanFord(int startNode)
{
    startNode--;

    std::vector<double> distance(vertices, INF);
    distance[startNode] = 0;

    for (int i = 1; i <= vertices; ++i)
    {
        bool updated = false;
        for (const auto& edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            double w = edge.weight;

            if (distance[u] != INF &&
                distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    for (const auto& edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        double w = edge.weight;

        if (distance[u] != INF && distance[u] + w < distance[v])
        {
            std::cout << "Граф содержит отрицательный цикл!" << std::endl;
            return false;
        }
    }

    printDistances(startNode, distance);
    return true;
}

void Graph::printDistances(int startNode, const std::vector<double>& dist)
{
    std::cout << "\n--- Результаты алгоритма Беллмана-Форда ---\n";
    std::cout << "Начальная вершина: " << startNode + 1 << std::endl;
    std::cout << "------------------------------------------\n";

    for (int i = 0; i < vertices; ++i) {
        std::cout << "Кратчайший путь до вершины " << i + 1 << ": ";
        if (dist[i] == INF) {
            std::cout << "НЕДОСТИЖИМ" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(2) << dist[i] << std::endl;
        }
    }
}
