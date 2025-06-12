#include <iostream>
#include <string>
#include <exception>
using namespace std;

// EXCEPȚII-le
class IndexOutOfBoundsException : public exception {
public:
    const char* what() const throw() override {
        return "Indexul este in afara domeniului!";
    }
};

class NullElementException : public exception {
public:
    const char* what() const throw() override {
        return "Elementul este NULL!";
    }
};

// COMPARATOR
class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

// ITERATOR PENTRU ARRAY
template<class T>
class ArrayIterator {
private:
    T** ptr;
    int index;
public:
    ArrayIterator(T** p = nullptr, int i = 0) : ptr(p), index(i) {}

    ArrayIterator& operator++() { index++; return *this; }
    ArrayIterator& operator--() { index--; return *this; }
    bool operator=(ArrayIterator<T>& other) 
    { 
        return ptr == other.ptr && index == other.index; 
    }
    bool operator!=(ArrayIterator<T>& other) 
    { 
        return index != other.index || ptr != other.ptr; 
    }
    T* GetElement() 
    { 
        return ptr ? ptr[index] : nullptr; 
    }
};

// CLASA ARRAY
template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void checkIndex(int index, bool allowEqual = false) const {
        if (index < 0 || (allowEqual ? index > Size : index >= Size)) {
            throw IndexOutOfBoundsException();
        }
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }

    Array(const Array<T>& other) {
        Capacity = other.Capacity;
        Size = other.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*other.List[i]);
    }

    T& operator[] (int index) {
        checkIndex(index);
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size == Capacity)
            throw exception(); 
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        checkIndex(index, true);
        if (Size == Capacity)
            throw exception();
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        checkIndex(index, true);
        if (Size + otherArray.Size > Capacity)
            throw exception();
        for (int i = Size - 1; i >= index; i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        checkIndex(index);
        delete List[index];
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    swap(List[i], List[j]);
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = compare(*List[mid], elem);
            if (cmp == 0)
                return mid;
            else if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = comparator->CompareElements(List[mid], (void*)&elem);
            if (cmp == 0)
                return mid;
            else if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }

    int GetSize() const { return Size; }
    int GetCapacity() const { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, 0); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List, Size); }
};

// Clasa de comparare
class IntCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* a = (int*)e1;
        int* b = (int*)e2;
        return (*a > *b) - (*a < *b); // echivalent cu: return *a - *b;
    }
};

// Funcție de comparare 
int CompareInts(const int& a, const int& b) {
    return (a > b) - (a < b);
}

int main() {
    try {
        cout << "=== TEST CONSTRUCTOR + ADAUGARE ===" << endl;
        Array<int> arr(10);
        arr += 7;
        arr += 3;
        arr += 9;
        arr += 1;

        cout << "Array initial: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST INSERT ===" << endl;
        arr.Insert(2, 5);
        cout << "Dupa insert(2, 5): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST INSERT (cu alt Array) ===" << endl;
        Array<int> alt(5);
        alt += 100;
        alt += 200;
        arr.Insert(1, alt);
        cout << "Dupa insert(1, alt): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST DELETE ===" << endl;
        arr.Delete(3);
        cout << "Dupa delete(3): ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST OPERATOR= ===" << endl;
        Array<int> copie;
        copie = arr;
        cout << "Copie: ";
        for (int i = 0; i < copie.GetSize(); ++i)
            cout << copie[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST SORT ===" << endl;
        arr.Sort();
        cout << "Sortat natural: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        arr.Sort(CompareInts);
        cout << "Sortat cu functie: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        IntCompare cmp;
        arr.Sort(&cmp);
        cout << "Sortat cu obiect Compare: ";
        for (int i = 0; i < arr.GetSize(); ++i)
            cout << arr[i] << ' ';
        cout << "\n";

        cout << "\n=== TEST BINARY SEARCH ===" << endl;
        int poz = arr.BinarySearch(100);
        cout << "BinarySearch(100): " << poz << "\n";
        poz = arr.BinarySearch(200, CompareInts);
        cout << "BinarySearch(200, CompareInts): " << poz << "\n";
        poz = arr.BinarySearch(5, &cmp);
        cout << "BinarySearch(5, Compare): " << poz << "\n";

        cout << "\n=== TEST FIND ===" << endl;
        cout << "Find(3): " << arr.Find(3) << "\n";
        cout << "Find(200, CompareInts): " << arr.Find(200, CompareInts) << "\n";
        cout << "Find(1, &cmp): " << arr.Find(1, &cmp) << "\n";

        cout << "\n=== TEST ITERATORI ===" << endl;
        ArrayIterator<int> it = arr.GetBeginIterator();
        ArrayIterator<int> end = arr.GetEndIterator();
        cout << "Iterare cu ArrayIterator: ";
        while (it != end) {
            cout << *it.GetElement() << ' ';
            ++it;
        }
        cout << "\n";

        cout << "\n=== TEST EXCEPTIE IndexOutOfBoundsException ===" << endl;
        cout << "Acces arr[100]: ";
        cout << arr[100] << endl; // va arunca excepție

    }
    catch (IndexOutOfBoundsException& ex) {
        cout << "IndexOutOfBoundsException prins: " << ex.what() << "\n";
    }
    catch (NullElementException& ex) {
        cout << "NullElementException prins: " << ex.what() << "\n";
    }
    catch (exception& ex) {
        cout << "Alta exceptie: " << ex.what() << "\n";
    }

    return 0;
}





