#pragma once

#include <stdexcept>
#include <string>

template<class T>
class Array {
public:
    Array(size_t capacity = INITIAL_CAPACITY)
        : _items(new T [capacity]), _capacity(capacity) {

    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
    Array(Array&&) = delete;
    Array& operator=(Array&&) = delete;

    ~Array() {
        delete [] _items;
    }

    T& operator[](size_t index) {
        if (index < _size) {
            return _items[index];
        } else {
            throw std::range_error("Out of range array index.");
        }
    }

    const T& operator[](size_t index) const {
        if (index < _size) {
            return _items[index];
        } else {
            throw std::range_error("Out of range array index.");
        }
    }

    size_t size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

    void push(const T& item) {
        if (_size == _capacity) {
            size_t newCapacity = static_cast<size_t>(_capacity * RESIZE_COEF);
            resize(newCapacity);
        }
        _items[_size++] = item;
    }

    T& back() {
        if (!_size) {
            throw std::length_error("Empty array has no back element.");
        } else {
            return _items[_size - 1];
        }
    }

    const T& back() const {
        if (!_size) {
            throw std::length_error("Empty array has no back element.");
        } else {
            return _items[_size - 1];
        }
    }

    T pop_back() {
        if (!_size) {
            throw std::length_error("Empty array has no back element.");
        } else {
            return _items[--_size];
        }
    }

private:
    void resize(size_t newCapacity) {
        if (newCapacity > _size) {
            T* newItems = new T [newCapacity];
            for (int i = 0; i < _size; ++i) {
                newItems[i] = _items[i];
            }
            delete [] _items;
            _items = newItems;
            _capacity = newCapacity;
        }
    }

    static const int INITIAL_CAPACITY = 10;
    static constexpr float RESIZE_COEF = 2.3f;
    T* _items = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
};

//NOTE: template specialization for int
//uses more efficient memcpy to copy array of primitives
template<>
void Array<int>::resize(size_t newCapacity) {
    if (newCapacity > _size) {
        int* newItems = new int [newCapacity];
        memcpy(newItems, _items, sizeof(int) * _size);
        delete [] _items;
        _items = newItems;
        _capacity = newCapacity;
    }
}