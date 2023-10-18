#include <iostream>
#include "Sorter.hpp"

using namespace std;

void printArray(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    
}

int main() 
{
    int arr[] = {1, 5, 3, 7, 9, 4, 8, 2, 6};

    cout<<"unsorted: "<<endl;
    printArray(arr, 9);

    Sorter sorter = Sorter(arr, 9);
    sorter.QuickSort(8, 0);
    cout<<endl;

    cout<<"sorted: "<<endl;
    printArray(arr, 9);

    cout<<endl;
}