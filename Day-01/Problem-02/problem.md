# 232. Implement Queue using Stacks

**Platform:** LeetCode
**Problem Link:** [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

## Problem Statement

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:
- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

**Notes:**
- You must use only standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

## Example Input/Output

**Example 1:**

**Input:**
```
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
```
**Output:**
```
[null, null, null, 1, 1, false]
```

**Explanation:**
```java
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

## Constraints

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

## Approach Explanation

We use two stacks (`s1` and `s2`) to simulate the queue. Since a queue follows First-In-First-Out (FIFO) and a stack follows Last-In-First-Out (LIFO), we do the following during a `push` operation to maintain the correct order in `s1`:

1. Move all existing elements from `s1` to `s2`.
2. Push the newly added element into `s1` (this element will be at the bottom of `s1`).
3. Move all elements back from `s2` to `s1`.

By doing this, the oldest element is always at the top of `s1`, allowing `pop()`, `peek()`, and `empty()` to operate in O(1) time directly from `s1`.
