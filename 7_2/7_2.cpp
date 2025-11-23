#include <iostream>
#include <iomanip>
#include <windows.h>

#include "BellmanFord.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    const int V = 8;
    Graph graph(V);

    std::cout << "Создание тестового графа..." << std::endl;

    graph.addEdge(0, 1, 23.0); graph.addEdge(1, 0, 23.0);
    graph.addEdge(0, 2, 12.0); graph.addEdge(2, 0, 12.0);
    graph.addEdge(1, 2, 25.0); graph.addEdge(2, 1, 25.0);
    graph.addEdge(1, 4, 22.0); graph.addEdge(4, 1, 22.0);
    graph.addEdge(1, 7, 35.0); graph.addEdge(7, 1, 35.0);
    graph.addEdge(2, 3, 18.0); graph.addEdge(3, 2, 18.0);
    graph.addEdge(3, 5, 20.0); graph.addEdge(5, 3, 20.0);
    graph.addEdge(4, 6, 14.0); graph.addEdge(6, 4, 14.0);
    graph.addEdge(4, 5, 23.0); graph.addEdge(5, 4, 23.0);
    graph.addEdge(5, 6, 24.0); graph.addEdge(6, 5, 24.0);
    graph.addEdge(6, 7, 16.0); graph.addEdge(7, 6, 16.0);

    int startNode = 1;

    std::cout << "Запуск алгоритма Беллмана-Форда от вершины 1:" <<std::endl;
    graph.BellmanFord(startNode);

    return 0;
}