#include <iostream>
#include <iomanip>
#include <fstream>
#include "heap.h"

//NOTE: return double to prevent int overflow
double get_median(const MaxHeap<int>& maxHeap, const MinHeap<int>& minHeap) {
    if (maxHeap.size() == minHeap.size()) {
        return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2.0;
    } else if (maxHeap.size() > minHeap.size()) {
        return maxHeap.top();
    } else {
        return minHeap.top();
    }
}

void balance_heaps(MaxHeap<int>& maxHeap, MinHeap<int>& minHeap) {
    if (maxHeap.size() > minHeap.size()) {
        int maxHeapTop = maxHeap.pop();
        minHeap.push(maxHeapTop);
    } else if (minHeap.size() > maxHeap.size()) {
        int minHeapTop = minHeap.pop();
        maxHeap.push(minHeapTop);
    }
}

void compute_median(std::istream& in, std::ostream& os) {
    MaxHeap<int> maxHeap;
    MinHeap<int> minHeap;
    int number;
    while (in >> number) {
        if (maxHeap.size() == minHeap.size()) {
            if (!maxHeap.isEmpty() && number < minHeap.top()) {
                maxHeap.push(number);
            } else {
                minHeap.push(number);
            }
        } else if (!maxHeap.isEmpty() && number > maxHeap.top()) {
            minHeap.push(number);
        } else {
            maxHeap.push(number);
        }

        if (minHeap.size() == maxHeap.size() + 2
            || maxHeap.size() == minHeap.size() + 2) {
            balance_heaps(maxHeap, minHeap);
        }

        os << std::setprecision(12)
            << get_median(maxHeap, minHeap)
            << std::endl;
    }
}

int main() {
    std::istream in(std::cin.rdbuf());
    std::ostream out(std::cout.rdbuf());
    compute_median(in, out);
}