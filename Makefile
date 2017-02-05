CCFLAGS=-std=c++11

.PHONY: test solution

test: heap.h tests/heap_test.cc
	g++ $(CCFLAGS) tests/heap_test.cc -o bin/heap_test

solution: heap.h solution_heaps.cc
	g++ $(CCFLAGS) solution_heaps.cc -o bin/solution_heaps