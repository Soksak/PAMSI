#pragma once
template  <typename T>
void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
template <typename T>
T& MedianOfThree(T * arr, int  first, int  last)
{
    int middle= (first +last)/2;
    if (arr[first] < arr[middle] && arr[middle] < arr[last])
        return (arr[middle]);

    if (arr[first] < arr[last] && arr[last] <= arr[middle])
        return (arr[last]);

    if (arr[middle] <= arr[first] && arr[first] < arr[last])
        return (arr[first]);

    if (arr[middle] < arr[last] && arr[last] <= arr[first])
        return (arr[last]);

    if (arr[last] <= arr[first] && arr[first] < arr[middle])
        return (arr[first]);

    if (arr[last] <= arr[middle] && arr[middle] <= arr[first])
        return (arr[middle]);
}


template <typename T>
int partition (T* arr, int start, int end)
{
    T  pivot = MedianOfThree(arr,start,end);
    int i = (start - 1);
    int j = end + 1;
    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }
        swap(arr[i],arr[j]);
    }
}





template <typename T>
void quickSort(T* arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot + 1, end);
    }
}
