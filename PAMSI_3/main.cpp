#include <iostream>
#include "Dijkstra.h"
#include <chrono>

using namespace std;

void PrintShortestPath(vector<int> &dist, int start)
{
    cout << "\nPrinting the shortest paths for node " << start << ".\n";
    for(int i = 0; i < dist.size(); i++)
    {
        cout << "The distance from node " << start << " to node " << i << " is: " << dist[i] << endl;
    }
}

int main() {
    double density[]={0.25,0.5,0.75,1};
    int Elements[]={10,50,100,250,500};
    float min=100000000, max;
    float all=0;
    for(int j=0;j<5;j++) {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 100; i++) {
                ListGraph* Graph =new ListGraph(Elements[j]);
                Graph->Random(density[k]);
                auto start = chrono::high_resolution_clock::now();
                dijkstra(*Graph,Elements[j],0);
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
                if((float)duration.count()<min){
                    min=(float)duration.count();
                }
                if((double)duration.count()>max){
                    max=(float)duration.count();
                }
                all+=(float)duration.count();
                delete Graph;
            }

            cout<<"Graf "<< Elements[j]<<" z gestoscia "<<density[k]<<"% ";
            cout<< "Minimalny czas:"<<min<<"  Maksymalny czas:"<< max<<"  Sredni czas:"<<all/100<<endl;
            min=10000000;max=0;all=0;
        }
    }


}