#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) 
{
    for (size_t i = 1; i < n; i++)
    {
        for (size_t k = i; k >= 1; k--)
        {
            if(arr[k] < arr[k-1])
            {
                int aux;
                aux = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = aux;
            } 
            else
            {
                break;
            }
        }
    }
    
}

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

    InsertionSort(arr, 9);
    cout<<endl;

    cout<<"sorted: "<<endl;
    printArray(arr, 9);

    cout<<endl;
}