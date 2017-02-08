#include <iostream>
#include <iomanip>
#include "array.h"

size_t first_greater_index(const Array<int>& array, int elem) {
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] > elem) {
            return i;
        }
    }
    return array.isEmpty() ? 0 : array.size();
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