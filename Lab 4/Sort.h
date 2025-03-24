#pragma once
class Sort
{private:
    // add data members
    int *list, Nr_elem;

    void QuickSortHelper(int left, int right, bool ascendent); // Funcție recursivă internă
    int Partition(int left, int right, bool ascendent); // Funcție pentru pivot
public:
    // add constuctors
    Sort(int, int, int);
    Sort();
    Sort(int*, int);
    Sort(int, ...);
    Sort(const char*);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

