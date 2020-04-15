#include <iostream>
#include <chrono>
#include <algorithm>
#include "MergeSort.h"
#include "QuickSort.h"
#include "IntroSort.h"
#include <fstream>


using namespace std;



template<typename T>
T* NewArray(int size, double percent)
{
    T* Tab = new T[size];
        for (int i = 0; i < size; i++) {
            Tab[i] = T(rand());
        }
        int a;
        a = static_cast<int>(percent * 0.01 * size);
        sort(Tab,Tab+a);
        return Tab;

}

int main() {
    fstream plik;
    double PercentArray[7]={0,25,50,75,95,99,99.7};
    int ElementsArray[5]={10000,50000,100000,500000,1000000};
    double min=100000000, max;
    double all=0;
    for(int j=0;j<5;j++) {
        for (int k = 0; k < 7; k++) {
            for (int i = 0; i < 100; i++) {
                int *Array = NewArray<int>(ElementsArray[j], PercentArray[k]);
                auto start = chrono::high_resolution_clock::now();
                mergeSort(Array, 0, ElementsArray[j]);
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
                if((double)duration.count()<min){
                    min=(double)duration.count();
                }
                if((double)duration.count()>max){
                    max=(double)duration.count();
                }
                all+=(double)duration.count();
                delete[] Array;
            }
            plik.open("MergeSort.txt", ios::out | ios::app);
            plik<<"Tablica "<< ElementsArray[j]<<" posortowana "<<PercentArray[k]<<"% "<<endl;
            plik<< "Minimalny czas:"<<min<<endl<<"Maksymalny czas:"<< max<<endl<<"Sredni czas:"<<all/100<<endl;
            plik.close();
            min=10000000;max=0;all=0;
        }
    }
}
