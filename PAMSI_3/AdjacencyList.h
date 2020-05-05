#pragma once
#include "GraphBase.h"


class ListGraph: public GraphBase
{
    struct Adjacency
    {
        int v;
        int weight;
    };
    using AdjacencyList = std::vector<Adjacency>;
    std::vector<AdjacencyList> adjacencyList;
public:
    ListGraph(int numOfVertices);
    void addEdge(int u, int v, int weight) override;
    void deleteEdge(int u, int v) override;
    std::vector<int> neighbours(int u) override;
    int weight(int u, int v) override;

};