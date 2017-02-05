#include <iostream>
#include <fstream>
#include "heap.h"

void compute_median(std::istream& in, std::ostream& os) {
    heap<int> minHeap;
    heap<int> maxHeap;
}

int main() {
    std::fstream fin("tests/test01.in");
    std::ostream out(std::cout.rdbuf());
    compute_median(fin, out);
}