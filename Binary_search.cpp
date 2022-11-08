/*

    This program demonstrates binary search on an array. (need a sorted array for that)
    
    *there are two types of binary search functions here:
        - normal one
        - recursive one


    * time complexity for linear search is O(n)
    * time complexity for binary search is O(log n)  - logarithm with base 2

    * constant space complexity for binary_search (do not need to add more during execution)

*/

#include <iostream>

int binary_search(int list[], int n, int target)
{
    int first = 0;
    int last = n-1;

    while(first <= last)
    {
        int midpoint = (first + last) / 2;

        if(list[midpoint] == target)
        {
            return midpoint;
        }
        else if(list[midpoint] < target)
        {
            first = midpoint + 1;
        }
        else // list[midpoint] > target
        {
            last = midpoint - 1;
        }
    }

    return -1;
}

int recursive_binary_search(int list[], int low, int high, int target)
{
    if(low <= high)
    {
        int midpoint = (low + high) / 2;

        if(list[midpoint]==target)
        {
            return midpoint;
        }
        else if(list[midpoint] < target)
        {
            return recursive_binary_search(list,midpoint+1,high,target);
        }
        else
        {
            return recursive_binary_search(list,low,midpoint-1,target); 
        }
    }
    else
    {
        return -1;
    }
}

void verify_search(int index)
{
    std::cout << std::endl;

    if(index != -1)
    {
        std::cout << "Target found at index: " << index <<std::endl;
    }
    else
    {
        std::cout << "Target not found" << std::endl;
    }

    std::cout << std::endl;
}

int main(){

    const int n = 10;
    int list[n] = {1,2,3,4,5,6,7,8,9,10}; // needs to be sorted

    int index = recursive_binary_search(list,0,n-1,11);

    verify_search(index);

}