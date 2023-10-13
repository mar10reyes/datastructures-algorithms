#include <iostream>
using namespace std;

void printArray(int arr[], int n);

void Merge(int left_array[], int left_arr_size, int right_array[], int right_arr_size, int arr[], int n) {
    
    int r = 0;
    int l = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(l<left_arr_size && r<right_arr_size) {

            if(left_array[l] < right_array[r]) {
                arr[i] = left_array[l];
                l++;
            } else {
                arr[i] = right_array[r];
                r++;
            }
        } else {

            //if only left arr values are left...
            if(l<left_arr_size) {
                arr[i] = left_array[l];
                l++;
            }

            //if only right arr values are left...
            if(r<right_arr_size) {
                arr[i] = right_array[r];
                r++;
            }
        }

    }
    
}

void MergeSort(int arr[], int n) 
{
    if(n == 1) {
        return;
    }

    int left_arr_size  = n/2;
    int right_arr_size = n - left_arr_size;

    int left_array[left_arr_size];
    int right_array[right_arr_size];

    for (int i = 0; i < n; i++)
    {
        if(i<left_arr_size) {
            left_array[i] = arr[i];
        } else {
            right_array[i-left_arr_size] = arr[i];
        }
    }
    
    MergeSort(left_array, left_arr_size);
    MergeSort(right_array, right_arr_size);
    Merge(left_array, left_arr_size, right_array, right_arr_size, arr, n);

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

    MergeSort(arr, 9);
    cout<<endl;

    cout<<"sorted: "<<endl;
    printArray(arr, 9);

    cout<<endl;
}