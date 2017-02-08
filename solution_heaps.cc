// This is a general solution that does not assume much about input integers.
// It uses two heaps to track the current median: a maxheap and a minheap,
// so that at any point in the algorithm all stored integers in the maxheap are
// smaller or equal to all stored integers in the minheap. Moreover at the end
// of a main solution loop both heaps differs in size by one at the most.
// Therefore, finding the median takes O(1) times - it is in the root of one or
// both heaps. Inserting the next number into this structure takes O(lgN) time,
// where N is the number of already processed numbers. Memory requirements is
// also O(N).

#include <iostream>
#include <iomanip>
#include "heap.h"

// NOTE: return double to prevent int overflow; assume at least one of the heaps
// is not empty
double get_median(const MaxHeap<int>& h1, const MinHeap<int>& h2) {
    if (h1.size() == h2.size()) {
        return (static_cast<double>(h1.top()) + h2.top()) / 2.0;
    } else if (h1.size() > h2.size()) {
        return h1.top();
    } else {
        return h2.top();
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