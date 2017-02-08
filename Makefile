CCFLAGS=-std=c++11 -Wall -O2

.PHONY: tests solutions

solutions: array.h heap.h solution_heaps.cc solution_quickselect.cc solution_sorted.cc
	g++ $(CCFLAGS) solution_sorted.cc -o bin/solution_sorted
	g++ $(CCFLAGS) solution_quickselect.cc -o bin/solution_quickselect
	g++ $(CCFLAGS) solution_heaps.cc -o bin/solution_heaps

tests: array.h heap.h tests/heap_test.cc
	g++ $(CCFLAGS) tests/heap_test.cc -o bin/heap_test