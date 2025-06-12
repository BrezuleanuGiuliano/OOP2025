#include <iostream>
#include <tuple>
using namespace std;

template<typename K, typename V>
class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry* entries;
    int size;
    int capacity;

    void resize() 
    {
        capacity *= 2;
        Entry* newEntries = new Entry[capacity];
        for (int i = 0; i < size; ++i) {
            newEntries[i] = entries[i];
        }
        delete[] entries;
        entries = newEntries;
    }

public:
    Map() {
        size = 0;
        capacity = 10;
        entries = new Entry[capacity];
    }

    ~Map() {
        delete[] entries;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < size; ++i) {

            if (entries[i].key == key)
                return entries[i].value;
        }

        if (size == capacity)
            resize();

        entries[size].key = key;
        entries[size].value = V(); // valoare implicită
        ++size;
        return entries[size - 1].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < size; ++i) {
            if (entries[i].key == key) {
                value = entries[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        delete[] entries;
        size = 0;
        capacity = 10;
        entries = new Entry[capacity];
    }

    bool Delete(const K& key) {
        for (int i = 0; i < size; ++i) {
            if (entries[i].key == key) {
                for (int j = i; j < size - 1; ++j) {
                    entries[j] = entries[j + 1];
                }
                --size;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) {
        for (int i = 0; i < other.size; ++i) {
            bool found = false;
            for (int j = 0; j < size; ++j) {
                if (entries[j].key == other.entries[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    // Iterator pentru range-based for + structured bindings
    struct Iterator {
        Map<K, V>& map;
        int index;

        Iterator(Map<K, V>& m, int i) : map(m), index(i) {}

        auto operator*() {
            return tuple<K&, V&, int>(map.entries[index].key, map.entries[index].value, index);
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }
    };

    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, size);
    }
};
int main() 
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        cout << "Index:" << index << ", Key=" << key << ", Value=" << value << endl;
    }

    m[20] = "result";
    //m[10] = "abc";
    for (auto [key, value, index] : m) 
    {
        cout << "Index:" << index << ", Key=" << key << ", Value=" << value << endl;
    }

    return 0;
}
