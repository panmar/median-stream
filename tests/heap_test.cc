#include <stdio.h>
#include "../heap.h"
#include "test.h"

void checkHeapSize() {
    MinHeap<int> heap;
    TEST(heap.size() == 0, "Empty heap size not equal 0.");
    heap.push(4);
    TEST(heap.size() == 1, "Incorrect heap size.");
    heap.push(4);
    TEST(heap.size() == 2, "Incorrect heap size.");
    heap.push(5);
    TEST(heap.size() == 3, "Incorrect heap size.");
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
    TEST(heap.size() == 13, "Incorrect heap size.");
    heap.popAndPush(423);
    TEST(heap.size() == 13, "Incorrect heap size.");
    heap.popAndPush(41233);
    TEST(heap.size() == 13, "Incorrect heap size.");
}

void checkMinHeapTop() {
    MinHeap<int> heap;
    heap.push(5);
    TEST(heap.top() == 5, "Incorrect min heap top.");
    heap.push(1);
    TEST(heap.top() == 1, "Incorrect min heap top.");
    heap.push(10);
    TEST(heap.top() == 1, "Incorrect min heap top.");
    heap.push(14);
    TEST(heap.top() == 1, "Incorrect min heap top.");
    heap.push(0);
    TEST(heap.top() == 0, "Incorrect min heap top.");
    heap.push(-7);
    TEST(heap.top() == -7, "Incorrect min heap top.");
    heap.push(-7);
    TEST(heap.top() == -7, "Incorrect min heap top.");
}

void checkMaxHeapTop() {
    MaxHeap<int> heap;
    heap.push(5);
    TEST(heap.top() == 5, "Incorrect max heap top.");
    heap.push(1);
    TEST(heap.top() == 5, "Incorrect max heap top.");
    heap.push(0);
    TEST(heap.top() == 5, "Incorrect max heap top.");
    heap.push(14);
    TEST(heap.top() == 14, "Incorrect max heap top.");
    heap.push(-7);
    TEST(heap.top() == 14, "Incorrect max heap top.");
    heap.push(10);
    TEST(heap.top() == 14, "Incorrect max heap top.");
    heap.push(0);
    TEST(heap.top() == 14, "Incorrect max heap top.");
    heap.push(-7);
    TEST(heap.top() == 14, "Incorrect max heap top.");
    heap.push(23);
    TEST(heap.top() == 23, "Incorrect max heap top.");
}

void checkMinHeapPopAndPush() {
    MinHeap<int> heap;
    heap.push(45);
    heap.push(32);
    int result = heap.popAndPush(66);
    TEST(result == 32, "Incorrect result of popAndPush().");
    TEST(heap.top() == 45, "Incorrect heap top after popAndPush().");
    result = heap.popAndPush(21);
    TEST(result == 45, "Incorrect result of popAndPush().");
    TEST(heap.top() == 21, "Incorrect heap top after popAndPush().");
}

void checkMaxHeapPopAndPush() {
    MaxHeap<int> heap;
    heap.push(45);
    heap.push(32);
    int result = heap.popAndPush(66);
    TEST(result == 45, "Incorrect result of popAndPush().");
    TEST(heap.top() == 66, "Incorrect heap top after popAndPush().");
    result = heap.popAndPush(21);
    TEST(result == 66, "Incorrect result of popAndPush().");
    TEST(heap.top() == 32, "Incorrect heap top after popAndPush().");
}

void checkMinHeapPop() {
    MinHeap<int> heap;
    heap.push(23);
    heap.push(41);
    heap.push(56);
    heap.push(71);
    heap.push(11);
    TEST(heap.top() == 11, "Incorrect heap top.");
    auto popped = heap.pop();
    TEST(popped == 11, "Incorrect heap pop() result.");
    TEST(heap.top() == 23, "Incorrect heap top.");
    popped = heap.pop();
    TEST(popped == 23, "Incorrect heap pop() result.");
    TEST(heap.top() == 41, "Incorrect heap top.");
    heap.push(91);
    heap.push(111);
    popped = heap.pop();
    TEST(popped == 41, "Incorrect heap pop() result.");
    TEST(heap.top() == 56, "Incorrect heap top.");
    popped = heap.pop();
    TEST(popped == 56, "Incorrect heap pop() result.");
    TEST(heap.top() == 71, "Incorrect heap top.");
}

int main() {
    checkHeapSize();
    checkMinHeapTop();
    checkMaxHeapTop();
    checkMinHeapPopAndPush();
    checkMaxHeapPopAndPush();
    checkMinHeapPop();
    return 0;
}