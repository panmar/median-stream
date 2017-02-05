#include <stdio.h>
#include "../heap.h"

#define ASSERT(expr, msg) if (!(expr)) { printf("%s:%d: %s\n", __FILE__, __LINE__, (msg)); }

void checkHeapSize() {
    MinHeap<int> heap;
    ASSERT(heap.size() == 0, "Empty heap size not equal 0.");
    heap.push(4);
    ASSERT(heap.size() == 1, "Incorrect heap size.");
    heap.push(4);
    ASSERT(heap.size() == 2, "Incorrect heap size.");
    heap.push(5);
    ASSERT(heap.size() == 3, "Incorrect heap size.");
    heap.push(6);
    heap.push(7);
    heap.push(6213);
    heap.push(62);
    heap.push(1236);
    heap.push(6231);
    heap.push(126);
    heap.push(-1236);
    heap.push(-12226);
    heap.push(12326);
    ASSERT(heap.size() == 13, "Incorrect heap size.");
    heap.popAndPush(423);
    ASSERT(heap.size() == 13, "Incorrect heap size.");
    heap.popAndPush(41233);
    ASSERT(heap.size() == 13, "Incorrect heap size.");
}

void checkMinHeapTop() {
    MinHeap<int> heap;
    heap.push(5);
    ASSERT(heap.top() == 5, "Incorrect min heap top.");
    heap.push(1);
    ASSERT(heap.top() == 1, "Incorrect min heap top.");
    heap.push(10);
    ASSERT(heap.top() == 1, "Incorrect min heap top.");
    heap.push(14);
    ASSERT(heap.top() == 1, "Incorrect min heap top.");
    heap.push(0);
    ASSERT(heap.top() == 0, "Incorrect min heap top.");
    heap.push(-7);
    ASSERT(heap.top() == -7, "Incorrect min heap top.");
    heap.push(-7);
    ASSERT(heap.top() == -7, "Incorrect min heap top.");
}

void checkMaxHeapTop() {
    MaxHeap<int> heap;
    heap.push(5);
    ASSERT(heap.top() == 5, "Incorrect max heap top.");
    heap.push(1);
    ASSERT(heap.top() == 5, "Incorrect max heap top.");
    heap.push(0);
    ASSERT(heap.top() == 5, "Incorrect max heap top.");
    heap.push(14);
    ASSERT(heap.top() == 14, "Incorrect max heap top.");
    heap.push(-7);
    ASSERT(heap.top() == 14, "Incorrect max heap top.");
    heap.push(10);
    ASSERT(heap.top() == 14, "Incorrect max heap top.");
    heap.push(0);
    ASSERT(heap.top() == 14, "Incorrect max heap top.");
    heap.push(-7);
    ASSERT(heap.top() == 14, "Incorrect max heap top.");
    heap.push(23);
    ASSERT(heap.top() == 23, "Incorrect max heap top.");
}

void checkMinHeapPopAndPush() {
    MinHeap<int> heap;
    heap.push(45);
    heap.push(32);
    int result = heap.popAndPush(66);
    ASSERT(result == 32, "Incorrect result of popAndPush().");
    ASSERT(heap.top() == 45, "Incorrect heap top after popAndPush().");
    result = heap.popAndPush(21);
    ASSERT(result == 45, "Incorrect result of popAndPush().");
    ASSERT(heap.top() == 21, "Incorrect heap top after popAndPush().");
}

void checkMaxHeapPopAndPush() {
    MaxHeap<int> heap;
    heap.push(45);
    heap.push(32);
    int result = heap.popAndPush(66);
    ASSERT(result == 45, "Incorrect result of popAndPush().");
    ASSERT(heap.top() == 66, "Incorrect heap top after popAndPush().");
    result = heap.popAndPush(21);
    ASSERT(result == 66, "Incorrect result of popAndPush().");
    ASSERT(heap.top() == 32, "Incorrect heap top after popAndPush().");
}

int main() {
    checkHeapSize();
    checkMinHeapTop();
    checkMaxHeapTop();
    checkMinHeapPopAndPush();
    checkMaxHeapPopAndPush();
    return 0;
}