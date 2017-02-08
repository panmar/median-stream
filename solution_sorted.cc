#include <iostream>
#include <iomanip>
#include "array.h"

// Returns first index in range [begin...end) that array[index] > elem
// Function uses recursive binary search with time complexity O(lgN), where N=end-begin
size_t upper_bound(const Array<int>& array, int begin, int end, int elem) {
    if (begin == end) {
        return begin;
    } else {
        int middle = (begin + end) / 2;
        if (array[middle] <= elem) {
            return upper_bound(array, middle + 1, end, elem);
        } else {
            return upper_bound(array, begin, middle, elem);
        }
    }
}

// Returns first array index from the beginning that array[index] > elem
size_t first_greater_index(const Array<int>& array, int elem) {
    if (array.isEmpty()) {
        return 0;
    } else {
        size_t index = upper_bound(array, 0, array.size(), elem);
        return index;
    }
}

void compute_median(std::istream& in, std::ostream& os) {
    int number;
    Array<int> numbers;
    while (in >> number) {
        size_t insert_index = first_greater_index(numbers, number);
        numbers.insert(number, insert_index);

        double median = 0.0;
        if (numbers.size() % 2) {
            median = numbers[numbers.size() / 2];
        } else {
            median = numbers[numbers.size() / 2 - 1];
            median += numbers[numbers.size() / 2];
            median /= 2.0;
        }

        os << std::setprecision(12) << median << std::endl;
    }
}

int main() {
    std::istream in(std::cin.rdbuf());
    std::ostream out(std::cout.rdbuf());
    compute_median(in, out);
}