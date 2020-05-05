#include "AdjacencyMatrix.h"

MatrixGraph::MatrixGraph(int numOfVertices): adjacencyMatrix(numOfVertices,numOfVertices) {
    _numOfVertices = numOfVertices;
}
void MatrixGraph::addEdge(int u, int v, int weight) {

    adjacencyMatrix(u, v) = weight;
}

void MatrixGraph::deleteEdge(int u, int v) {

    adjacencyMatrix(u, v) = std::numeric_limits<int>::min();
}

std::vector<int> MatrixGraph::neighbours(int u) {

    std::vector<int> neighboursVec;
    for (int i = 0; i < _numOfVertices; ++i)
    {
        if (adjacencyMatrix(u, i) != -1)
            neighboursVec.push_back(i);
    }
    return neighboursVec;
}

int MatrixGraph::weight(int u, int v) {
    return adjacencyMatrix(u,v);
}
