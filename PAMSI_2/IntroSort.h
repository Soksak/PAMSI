#include "QuickSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include <math.h>



template <typename T>
void IntrosortUtil(T* arr, int  begin,
                   int  end, int depthLimit)
{

    int size = end - begin;


    if (size < 9)
    {
        insertionSort(arr,size);
        return;
    }


    if (depthLimit == 0)
    {
        heapSort(arr,size);
        return;
    }
    else if (begin < end) {
        int pivot = partition(arr, begin, end);
        IntrosortUtil(arr, begin, pivot, --depthLimit);
        IntrosortUtil(arr, pivot + 1, end, --depthLimit);
    }
}

template <typename T>
void Introsort(T* arr, int begin, int end)
{
    int depthLimit = (int)log(end-begin)*2;


    IntrosortUtil(arr, begin, end, depthLimit);
}