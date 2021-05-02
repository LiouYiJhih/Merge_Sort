#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q,int r)
{
    // Create L <- A[p...q] and M <- A[q+1..r] 
    int n1 = q - p + 1; // A[1...5] => n1=5-1+1=5
    int n2 = r - q;     // M[6...10] => n2=10-5=5 

    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
    {
        // 把陣列前半段存入L
        L[i] = arr[p+i];
    }
    for (int j = 0; j < n2; j++)
    {
        // 把陣列前半段存入M
        M[j] = arr[q+1+j];
    }

     // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = M[j];
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
        arr[k] = M[j];
        j++;
        k++;
    }
}
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    // l : array first index, r = array last index
    if (l < r)
    {
        //m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;
        printf("m = %d\n", m);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1, 4, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size = %d\n", size);
    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}