#Running median problem

**Problem**: *Given unordered stream of integers make an algorithm returning a median of already registered numbers.*

##Solution 1: sorted array

This solution maintains sorted array. Finding the median takes **O(1)** and inserting new element into the array **O(N)** (finding insertion index using binary search takes **O(lgN)** and repairing the array **O(N)**.)

##Solution 2: quickselect partition

This solution uses partitioning of stored integers into two parts: one part contains numbers smaller or equal than chosen pivot and second part greater. Then the part containing the median is chosen and last step is repeated recursively until the median is found. Worst case complexity is **O(N<sup>2</sup>)**, where **N** is the number of already processed numbers. Memory requirement is **O(N)**.

#####Possible improvements#####
* Change pivot chosing strategy (e.g. *median of medians of 5*) to get **O(N)** worst-case complexity.

##Solution 3: min-max heaps

This is a general solution that does not assume anything about input integers. It uses two heaps to track the current median - a max-heap and a min-heap, so that at any point in the algorithm all stored integers in the max-heap are smaller or equal to all stored integers in the min-heap. Moreover at the end of a main solution loop both heaps differs in size by one at the most. Therefore, finding the median takes **O(1)** times - it is in the root of one or both heaps. Inserting the next number into this structure takes **O(lgN)** time, where N is the number of already processed numbers. Memory requirements is also **O(N)**. 

##Results##

| Solutions          | test01.in  | test02.in  | test03.in  | test04.in  | test05.in  | test06.in  |
| ------------------ | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
|*sorted array*      | 0.09s      | 2.45s      | 0.37s      | 0.95s      | 0.70s      | 0.25s      |
|*quickselect*       | 0.18s      | 9.13s      | 1.02s      | 3.41s      | 2.41s      | 0.70s      |
|*min-max heaps*     | 0.08s      | 0.68s      | 0.22s      | 0.32s      | 0.27s      | 0.14s      |

##Build##
```
make solutions
make tests
```
