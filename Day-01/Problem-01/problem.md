# 225. Implement Stack using Queues

**Platform:** LeetCode
**Problem Link:** [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

## Problem Statement

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:
- `void push(int x)` Pushes element x to the top of the stack.
- `int pop()` Removes the element on the top of the stack and returns it.
- `int top()` Returns the element on the top of the stack.
- `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

**Notes:**
- You must use only standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
- Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

## Example Input/Output

**Example 1:**

**Input:**
```
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
```
**Output:**
```
[null, null, null, 2, 2, false]
```

**Explanation:**
```java
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

## Constraints

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
- All the calls to `pop` and `top` are valid.

## Approach Explanation

We use two queues (`q1` and `q2`) to simulate the stack. Since a stack is Last-In-First-Out (LIFO) and a queue is First-In-First-Out (FIFO), we reverse the order when pushing a new element:

1. Move all existing elements from `q1` to `q2`.
2. Push the newly added element into `q1`. This ensures it stays at the front.
3. Move all elements back from `q2` to `q1`.

Now, `q1` correctly maintains elements in stack order (newest element is at the front). The operations `pop()`, `top()`, and `empty()` can directly interact with `q1`.
