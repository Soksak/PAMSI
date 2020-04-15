

template <typename T>
void merge(T* arr, int first, int middle, int last)
{
    int i, j, k;
    int n1 = middle - first + 1;
    int n2 =  last - middle;

    T* L = new T[n1];
    T* R = new T[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[first + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1+ j];


    i = 0;
    k = first;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}


template <typename T>
void mergeSort(T* arr, int first, int last)
{
    if (first < last)
    {

        int middle = first+(last-first)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);

        merge(arr, first, middle, last);
    }
}