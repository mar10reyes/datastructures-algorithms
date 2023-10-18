#include "Sorter.hpp"
#include <iostream>

Sorter::Sorter(int* arr, int n)
{
    this->arr = arr;
    this->n = n;
}

Sorter::~Sorter()
{
}

void Sorter::BucketSort()
{
    for (size_t i = 1; i < n; i++) {
        for (size_t k = i; k >= 1; k--) {
            if(arr[k] < arr[k-1]) {
                int aux;
                aux = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = aux;
            } 
            else {
                break;
            }
        }
    }
}

void Sorter::InsertionSort() {
    for (size_t i = 1; i < n; i++) {
        for (size_t k = i; k >= 1; k--) {
            
            if(arr[k] < arr[k-1]) {
                int aux;
                aux = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = aux;
            } 
            else {
                break;
            }
        }
    }
    
}

void Sorter::QuickSort(int upper_limit, int lower_limit) {
    
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
    QuickSort(pivot_pos-1, lower_limit);
    //sort right side
    QuickSort(upper_limit, pivot_pos+1);
}

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

void _MergeSort(int arr[], int n) 
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
    
    _MergeSort(left_array, left_arr_size);
    _MergeSort(right_array, right_arr_size);
    Merge(left_array, left_arr_size, right_array, right_arr_size, arr, n);
}

void Sorter::MergeSort() {
    _MergeSort(this->arr, this->n);
}