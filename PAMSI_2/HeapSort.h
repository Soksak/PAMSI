
template  <typename T>
void swapH(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}


template <typename T>
void heapify(T* arr, int size, int parentIndex)
{
    int largest = parentIndex;
    int l = 2*parentIndex + 1;
    int r = 2*parentIndex + 2;


    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != parentIndex)
    {
        swapH(&arr[parentIndex], &arr[largest]);

        heapify(arr, size, largest);
    }
}

template <typename T>
void heapSort(T* arr, int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i=size-1; i>0; i--)
    {
        swapH(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
} 