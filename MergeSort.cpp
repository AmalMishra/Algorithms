#include <iostream>

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int L[size1], R[size2];

    for (i = 0; i < size1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < size2; j++)
        R[j] = arr[middle + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2)
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

    while (i < size1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int m = left+(right-left)/2;

        mergeSort(arr, left, m);
        mergeSort(arr, m+1, right);

        merge(arr, left, m, right);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout<< A[i]<<" ";
    std:: cout<<"\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    std:: cout<< "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std:: cout<<" \nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
