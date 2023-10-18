#ifndef SORTER_HPP
#define SORTER_HPP

class Sorter
{
private:
    int* arr;
    int n;
public:
    Sorter(int* arr, int n);
    ~Sorter();

    void BucketSort();
    void InsertionSort();
    void QuickSort(int upper_limit, int lower_limit);
    void MergeSort();
};

#endif // SORTER_HPP