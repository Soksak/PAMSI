#pragma once
#include <queue>
#include "AdjacencyMatrix.h"
#include <iostream>
using namespace std;
typedef std::pair<int, int> iPair;

std::vector<int> dijkstra(GraphBase& graph,int V, int src) {

    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while(pq.empty() == false)
    {
        int u = pq.top().first;
        pq.pop();

        for(int i = 0; i < graph.neighbours(u).size(); i++)
        {
            vector<int> a=graph.neighbours(u);
            int v = a[i];
            int weight = graph.weight(u,a[i]);

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v, dist[v]));
            }

        }
    }

    return dist;

}