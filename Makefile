CCFLAGS=-std=c++11 -Wall -O2

.PHONY: tests solutions

solutions: array.h heap.h solution_heaps.cc solution_quickselect.cc
	g++ $(CCFLAGS) solution_heaps.cc -o bin/solution_heaps
	g++ $(CCFLAGS) solution_quickselect.cc -o bin/solution_quickselect

tests: array.h heap.h tests/heap_test.cc
	g++ $(CCFLAGS) tests/heap_test.cc -o bin/heap_test