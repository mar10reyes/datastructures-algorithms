#include <iostream>
using namespace std;

void printArray(int arr[], int n);

void QuickSort(int arr[], int upper_limit, int lower_limit) {
    
    if(upper_limit < lower_limit) {
        return;
    }

    int pivot_pos = upper_limit;
    int j = 0;
    int i = 0;
    
    for(; j<upper_limit; j++) {
        if(i==0 && j==0) {
            j++;
        }
        if(arr[pivot_pos] > arr[j]) {
            i++;
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }

    if(i < upper_limit) {
        i++;
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        pivot_pos = i; //new pivot pos
    }

    //sort left side
    QuickSort(arr, pivot_pos-1, lower_limit);
    //sort right side
    QuickSort(arr, upper_limit, pivot_pos+1);
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

    cout<<endl;
    cout<<"-------------"<<endl;

    QuickSort(arr, 8, 0);
    cout<<endl;

    cout<<"sorted: "<<endl;
    printArray(arr, 9);

    cout<<endl;
}