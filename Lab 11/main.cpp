#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sorter {
public:
    void Sort(vector<T>& arr) {
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
                    arr[j] = arr[j + 2];       
                    arr[j + 1] = temp;
                }
            }
        }

        if (n == 1) return; 
    }
};


template <typename T>
bool isSortedAscending(const vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

void testSorting() {
    Sorter<int> sorter;

    vector<vector<int>> tests = {
        {5, 3, 2, 4, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {42},
        {}
    };

    for (int i = 0; i < tests.size(); ++i) {
        sorter.Sort(tests[i]);
        cout << "Test " << i + 1 << ": "<< (isSortedAscending(tests[i]) ? "PASS" : "FAIL") << "\n";
    }
}

int main() 
{
    testSorting();
    return 0;
}
