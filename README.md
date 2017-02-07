#Running median problem

**Problem**: *Given unordered stream of integers make an algorithm returning a median of already registered numbers.*

##Solution 1: min-max heaps

This is a general solution that does not assume anything about input integers. It uses two heaps to track the current median - a max-heap and a min-heap, so that at any point in the algorithm all stored integers in the max-heap are smaller or equal to all stored integers in the min-heap. Moreover at the end of a main solution loop both heaps differs in size by one at the most. Therefore, finding the median takes **O(1)** times - it is in the root of one or both heaps. Inserting the next number into this structure takes **O(lgN)** time, where N is the number of already processed numbers. Memory requirements is also **O(N)**. 

| Test    | test01.in  | test02.in  | test03.in  | test04.in  | test05.in  | test06.in  |
| ------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
|**Time** | 0.01s      | 0.01s      | 0.01s      | 0.01s      | 0.01s      | 0.01s      |

##Solution 2: running window 

A rolling window solution maintains a set of data numbers closest to the current median. It is particulary useful when the noise to signal ratio is relatively small (median do not oscilate too much) and no frequent window recalculations are needed.

The rolling window is based on histogram of values; an index represents the stored number and the value represents the number's count. Inserting a new number (assuming it fits into the window) is therefore O(1) operation and finding new median (assuming it is present in the window) is O(K), where K is the dimension of the window.

// min/max arrays

// Pesimistic times:

// Improvements:

| Test    | test01.in  | test02.in  | test03.in  | test04.in  | test05.in  | test06.in  |
| ------- | ---------- | ---------- | ---------- | ---------- | ---------- | ---------- |
|**Time** | 0.01s      | 0.01s      | 0.01s      | 0.01s      | 0.01s      | 0.01s      |
