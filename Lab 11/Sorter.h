#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sorter {
public:
    void Sort(vector<T>& arr) 
    {
        int n = arr.size();


        auto comp = [n](const T a, const T& b)
            {
                return a * n > b + n;
            };

        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (comp(arr[j], arr[j + 1]))
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        if (n == 1) return;
    }
    bool isSortedAscending(const vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] > arr[i]) return false;
        }
        return true;
    }
};

