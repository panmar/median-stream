#include <stdexcept>
#include <string>

void swap(int& a, int& b) {
    //NOTE: we assume that &a != &b
    a ^= b;
    b ^= a;
    a ^= b;
}

template<class T>
void resize(T*& array, size_t arraySize, size_t newSize) {
    if (newSize > arraySize) {
        T* newArray = new T [newSize];
        for (int i = 0; i < arraySize; ++i) {
            newArray[i] = array[i];
        }
        delete [] array;
        array = newArray;
    }
}

template<>
void resize(int*& array, size_t arraySize, size_t newSize) {
    if (newSize > arraySize) {
        int* newArray = new int [newSize];
        memcpy(newArray, array, sizeof(int) * arraySize);
        delete [] array;
        array = newArray;
    }
}

template<class T, class Comparator>
class Heap {
public:
    Heap(int capacity = _initialCapacity) : _capacity(capacity) {
        _items = new T[capacity];
    }

    Heap(const Heap&) = delete;
    Heap operator=(const Heap&) = delete;
    Heap(Heap&& o) = delete;
    Heap operator=(Heap&&) = delete;

    ~Heap() { delete [] _items; }

    int size() const { return _size; }

    T top() const {
        if (!_size) {
            throw std::length_error("There is no top element in empty heap.");
        } else {
            return _items[0];
        }
    }

    void push(T item) {
        if (_size == _capacity) {
            int newSize = static_cast<int>(_resizeCoefficient * _capacity);
            resize(_items, _size, newSize);
        }

        int index = _size;
        _items[_size++] = item;
        while (index > 0 && _cmp(_items[index], _items[parentIndex(index)])) {
            swap(_items[index], _items[parentIndex(index)]);
            index = parentIndex(index);
        }
    }

    T popAndPush(T item) {
        if (!_size) {
            throw std::length_error("Cannot pop from an empty heap.");
        }

        T result = _items[0];
        _items[0] = item;

        int index = 0;
        while (lchildIndex(index) < _size) {
            int lci = lchildIndex(index);
            int rci = rchildIndex(index);

            if (rci < _size && _cmp(_items[rci], _items[lci]) && _cmp(_items[rci], _items[index])) {
                swap(_items[index], _items[rci]);
                index = rci;
            } else if (_cmp(_items[lci], _items[index])) {
                swap(_items[index], _items[lci]);
                index = lci;
            } else {
                break;
            }
        }

        return result;
    }

private:
    int parentIndex(int index) const {
        return (index - 1) / 2;
    }

    int lchildIndex(int index) const {
        return index * 2 + 1;
    }

    int rchildIndex(int index) const {
        return index * 2 + 2;
    }

    static const int _initialCapacity = 10;
    static constexpr float _resizeCoefficient = 2.0f;
    Comparator _cmp;
    T* _items = nullptr;
    int _capacity = 0;
    int _size = 0;
};

template<class T>
class MinComparator {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};

template<class T>
class MaxComparator {
public:
    bool operator()(T a, T b) {
        return a > b;
    }
};

template<class T>
using MinHeap = Heap<T, MinComparator<T>>;

template<class T>
using MaxHeap = Heap<T, MaxComparator<T>>;