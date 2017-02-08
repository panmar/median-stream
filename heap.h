#pragma once

#include <stdexcept>
#include "array.h"

void swap(int& a, int& b) {
    if (&a != &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

template<class T, class Comparator>
class Heap {
public:
    Heap() {
    }

    Heap(const Heap&) = delete;
    Heap& operator=(const Heap&) = delete;
    Heap(Heap&&) = delete;
    Heap& operator=(Heap&&) = delete;

    ~Heap() { }

    size_t size() const { return _items.size(); }

    bool isEmpty() const { return _items.isEmpty(); }

    const T& top() const {
        if (_items.isEmpty()) {
            throw std::length_error("There is no top element in empty heap.");
        } else {
            return _items[0];
        }
    }

    void push(T item) {
        int index = _items.size();
        _items.push(item);
        while (index > 0 && _cmp(_items[index], _items[parentIndex(index)])) {
           swap(_items[index], _items[parentIndex(index)]);
           index = parentIndex(index);
        }
    }

    // Returns the root element of the heap, removing it as well
    T pop() {
        if (_items.isEmpty()) {
            throw std::length_error("Cannot pop from an empty heap.");
        }

        T result = _items[0];
        _items[0] = _items.pop_back();
        propagate_down(0);
        return result;
    }

    T popAndPush(T item) {
        if (_items.isEmpty()) {
            throw std::length_error("Cannot pop from an empty heap.");
        }

        T result = _items[0];
        _items[0] = item;

        int index = 0;
        while (lchildIndex(index) < _items.size()) {
            int lci = lchildIndex(index);
            int rci = rchildIndex(index);

            if (rci < _items.size() && _cmp(_items[rci], _items[lci]) && _cmp(_items[rci], _items[index])) {
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
    // Propagate the unordered item at index so that after completing
    // the function whole heap is again in proper order.
    void propagate_down(size_t index) {
        while (lchildIndex(index) < _items.size()) {
            int lci = lchildIndex(index);
            int rci = rchildIndex(index);

            if (rci < _items.size() && _cmp(_items[rci], _items[lci]) && _cmp(_items[rci], _items[index])) {
                swap(_items[index], _items[rci]);
                index = rci;
            } else if (_cmp(_items[lci], _items[index])) {
                swap(_items[index], _items[lci]);
                index = lci;
            } else {
                break;
            }
        }
    }

    //NOTE: an index must be greater than 0
    int parentIndex(int index) const {
        return (index - 1) / 2;
    }

    int lchildIndex(int index) const {
        return index * 2 + 1;
    }

    int rchildIndex(int index) const {
        return index * 2 + 2;
    }

    Comparator _cmp;
    Array<T> _items;
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