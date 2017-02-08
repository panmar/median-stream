// This solution tries to find median of unsorted array each time new sample is
// submitted. It uses partitioning of input data into two parts: one part
// contains numbers smaller or equal than chosen pivot and second part greater
// This step is repeated recursively until median is found. Worst case complexity
// is O(N^2), where N is the number of already processed numbers. Memory
// requirement is O(N).

// Possible improvements: change pivot chosing strategy (e.g. median of medians of 5)
// to get O(n) worst-case complexity.

#include <iostream>
#include <iomanip>
#include "array.h"

int partition(Array<int>& array, int start, int end) {
    int pivot_value = array[end];
    while (start < end) {
        while (array[start] < pivot_value) ++start;
        while (array[end] > pivot_value) --end;
        if (array[start] == array[end]) {
            ++start;
        } else if (start < end) {
            swap(array[start], array[end]);
        }
    }
    return end;
}

int nth_element(Array<int>& array, int start, int end, int nth) {
    if (start == end) {
        return array[start];
    }
    int partition_end = partition(array, start, end);
    int length = partition_end - start + 1;
    if (nth == length) {
        return array[partition_end];
    } else if (nth < length) {
        return nth_element(array, start, partition_end - 1, nth);
    } else {
        return nth_element(array, partition_end + 1, end, nth - length);
    }
}

void compute_median(std::istream& in, std::ostream& os) {
    Array<int> numbers;
    int number;
    while (in >> number) {
        numbers.push(number);
        double median = 0.0;
        if (numbers.size() % 2) {
            median = nth_element(numbers, 0, numbers.size() - 1, numbers.size() / 2 + 1);
        } else {
            median += nth_element(numbers, 0, numbers.size() - 1, numbers.size() / 2);
            median += nth_element(numbers, 0, numbers.size() - 1, numbers.size() / 2 + 1);
            median /= 2.0;
        }
        os << std::setprecision(12)
            << median
            << std::endl;
    }
}

int main() {
    std::istream in(std::cin.rdbuf());
    std::ostream out(std::cout.rdbuf());
    compute_median(in, out);
}