// This solution tries to find a median of unsorted array each time new sample
// is submitted. It uses partitioning of input data into two parts: one part
// contains numbers smaller or equal than chosen pivot and second part greater.
// Then the set containing the median is chosen and last step is repeated
// recursively until the median is found. Worst case complexity is O(N^2),
// where N is the number of already processed numbers. Memory requirement is O(N).

// Possible improvements: change pivot chosing strategy (e.g. median of medians of 5)
// to get O(n) worst-case complexity.

#include <iostream>
#include <iomanip>
#include "array.h"

// Partition array[start...end] elements into two sets: array[start...result] and
// array(result...end], so that elements in first set are smaller than elements
// in the second set.
int partition(Array<int>& array, int start, int end) {
    // NOTE: a middle element is chosen as a pivot because the passed array
    // has tendency to be sorted the longer this solution is running
    int pivot_index = start + (end - start) / 2;
    int pivot_value = array[pivot_index];
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