### Monotonic Queue

##### Keep the max/min value on a scrolling forward range. In average O(1) time.

Example: [luogu 3957](../luogu/Luogu3957.cpp).

Monotonic Queue can keep a average O(1) of time. (It use O(n) of time to traverse all element for once)

#### construction

* Base on deque, use STL deque template.
* each time when iteration advance, delete the out-of-range elements by calling ```pop_front()```.
* each time adding new elements at back, call ```pop_back()``` to delete elements form back.  
  this action is to keep the deque monotonic.  
  It's easy to prove that the deque will always keep the maximum / minimum value in the current range.
  (the same even after any deleting / inserting).