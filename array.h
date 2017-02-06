#pragma once

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
        //TODO: check range
        return _items[index];
    }

    const T& operator[](size_t index) const {
        //TODO: check range
        return _items[index];
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

    void insert_after(int index, const T& item) {

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