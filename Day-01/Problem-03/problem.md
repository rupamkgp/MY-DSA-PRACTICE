# 155. Min Stack

**Platform:** LeetCode
**Problem Link:** [Min Stack](https://leetcode.com/problems/min-stack/)

## Problem Statement

Design a stack that supports `push`, `pop`, `top`, and retrieving the minimum element in constant time.

Implement the `MinStack` class:
- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

## Example Input/Output

**Example 1:**

**Input:**
```
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
```
**Output:**
```
[null,null,null,null,-3,null,0,-2]
```

**Explanation:**
```java
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

## Constraints

- `-2^31 <= val <= 2^31 - 1`
- Methods `pop`, `top` and `getMin` operations will always be called on non-empty stacks.
- At most `3 * 10^4` calls will be made to `push`, `pop`, `top`, and `getMin`.

## Approach Explanation

We can use a single stack that stores pairs of integers: `{value, current_minimum}`.
- Whenever we push a new `val`, we check what the current minimum is.
- The new minimum will be the minimum of `val` and the previous minimum (which is stored in the `second` element of the pair at the top of the stack).
- Since we store the minimum value at that exact state of the stack along with every pushed element, `getMin()` simply returns `s.top().second` in `O(1)` time.
- All other operations operate naturally on `s.top().first` or the stack itself in `O(1)` time.
