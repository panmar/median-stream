CCFLAGS=-std=c++11 -Wall -O2

.PHONY: test solution

test: array.h heap.h tests/heap_test.cc
	g++ $(CCFLAGS) tests/heap_test.cc -o bin/heap_test

solution: array.h heap.h solution_heaps.cc
	g++ $(CCFLAGS) solution_heaps.cc -o bin/solution_heaps