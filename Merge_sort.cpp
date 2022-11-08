/*

    This program merge sort on an array.
    
    It returns new array in ascending order

    Steps:
        - find the midpoint of the list and devide int o sublists
        - recursively sort the sublists created previously
        - merge (combine) sorted sublists 


    in deviding we take O(log n) time
    in merging we need n number of merge operations
    = overall rutime O(n log n)
    
    space complexity is n
*/

#include <iostream>


void merge(int arr[], int left, int middle, int right)
{

    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // new arrays left and right
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = arr[left + i];
    for(int i=0; i<n2; i++) R[i] = arr[middle + 1 + i];

    i = 0;  // start of a left array (L)
    j = 0;  // start of a right array (R)
    k = left;  // start of a new merged array

    // sorting while putting array together
    while(i<n1 && j<n2)
    {
        if(L[i] >= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    // if we have some leftovers
    while(i<n1)
    {
        arr[k] = L[i];
        k++, i++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        k++, j++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;

        merge_sort(arr, left, middle);
        merge_sort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is: ";
    printArray(arr, arr_size);
 
    merge_sort(arr, 0, arr_size - 1);
 
    std::cout << "Sorted array is: ";
    printArray(arr, arr_size);

    return 0;
}