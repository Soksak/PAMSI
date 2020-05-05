#include "GraphBase.h"

void GraphBase::Random(double density) {

    for(int i=0;i<_numOfVertices;i++){
        for(int j=0;j<_numOfVertices;j++){
            if (i!=j){
                addEdge(i,j,rand() % 100);
            }
        }
    }
    int Edges= ( _numOfVertices * (_numOfVertices - 1));
    int Delete=Edges-(int)(density * _numOfVertices * (_numOfVertices - 1));
    for (int i=0;i<Delete;i++){
        deleteEdge(rand() % _numOfVertices, rand() % _numOfVertices);
    }

}