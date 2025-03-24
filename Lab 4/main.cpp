#include "Sort.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Test constructor cu numere random:\n";
    Sort s1;
    s1.Print();

    cout << "\nTest constructor cu array existent:\n";
    int arr[] = { 42, 23, 16, 15, 8, 4 };
    Sort s2(arr,6);
    s2.Print();

    cout << "\nTest constructor cu initializer list (varargs):\n";
    Sort s3(5, 5, 2, 9, 1, 7);
    s3.Print();

    cout << "\nTest constructor cu string de numere separate prin virgula:\n";
    char str[] = "10,3,6,1,9,2";
    Sort s4(str);
    s4.Print();

    cout << "\nTestare functii de sortare:\n     ";
    cout << "\nLista initiala:\n     ";
    s1.Print();

    cout << "\nQuickSort crescator:\n     ";
    s1.QuickSort(true);
    s1.Print();

    cout << "\nBubbleSort crescator:\n     ";
    s1.BubbleSort(true);
    s1.Print();

    cout << "\nInsertionSort descrescator:\n     ";
    s1.InsertSort(false);
    s1.Print();

    

    return 0;
}