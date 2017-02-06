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
        } else if (maxHeap.size() > minHeap.size()) {
            if (number >= maxHeap.top()) {
                minHeap.push(number);
            } else {
                int prevMaxTop = maxHeap.popAndPush(number);
                minHeap.push(prevMaxTop);
            }
        } else {
            if (number <= minHeap.top()) {
                maxHeap.push(number);
            } else {
                int prevMinTop = minHeap.popAndPush(number);
                maxHeap.push(prevMinTop);
            }
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