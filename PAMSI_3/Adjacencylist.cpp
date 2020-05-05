#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


ListGraph::ListGraph(int numOfVertices) {
    adjacencyList.resize(numOfVertices);
    _numOfVertices = numOfVertices;
}

void ListGraph::addEdge(int u, int v, int weight) {

    Adjacency adj{v, weight};
    adjacencyList[u].push_back(adj);

}

void ListGraph::deleteEdge(int u, int v) {

     auto& adjList = adjacencyList[u];
     std::remove_if(adjList.begin(), adjList.end(), [v](const Adjacency& adj){
     return adj.v == v;
     });

}

std::vector<int> ListGraph::neighbours(int u) {

    std::vector<int> neighboursVec;
    AdjacencyList& neighboursList = adjacencyList[u];
    std::transform(neighboursList.begin(), neighboursList.end(), std::back_inserter(neighboursVec),
                   [](const Adjacency& adj) { return adj.v; });
    return neighboursVec;
}

int ListGraph::weight(int u, int v) {

    auto& adjList = adjacencyList[u];
    auto it = std::find_if(adjList.begin(), adjList.end(), [v](const Adjacency& adj) { return v == adj.v; });
    return it->weight;


}