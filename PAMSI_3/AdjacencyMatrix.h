#pragma once
#include "AdjacencyList.h"

class MatrixGraph: public GraphBase
{
    class Matrix
    {
    public:
        Matrix(int n, int m, int defaultValue = -1) : ncols{n} { vec.resize(n * m, defaultValue); }
        int& operator()(int x, int y) { return vec[x * ncols + y]; }

    private:
        std::vector<int> vec;
        int ncols;
    };
    Matrix adjacencyMatrix;
    int V; // liczba wierzcholkow
public:
    MatrixGraph(int numOfVertices);
    void addEdge(int u, int v, int weight) override;
    void deleteEdge(int u, int v) override;
    std::vector<int> neighbours(int u) override;
    int weight(int u, int v) override;

};