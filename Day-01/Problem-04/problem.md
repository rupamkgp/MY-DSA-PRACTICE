# 946. Validate Stack Sequences

**Platform:** LeetCode
**Problem Link:** [Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

## Problem Statement

Given two integer arrays `pushed` and `popped` each with distinct values, return `true` if this could have been the result of a sequence of push and pop operations on an initially empty stack, or `false` otherwise.

## Example Input/Output

**Example 1:**

**Input:** 
```
pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
```
**Output:** `true`

**Explanation:** 
We might do the following sequence:
- push(1), push(2), push(3), push(4),
- pop() -> 4,
- push(5),
- pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

**Example 2:**

**Input:** 
```
pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
```
**Output:** `false`

**Explanation:** 
1 cannot be popped before 2.

## Constraints

- `1 <= pushed.length <= 1000`
- `0 <= pushed[i] <= 1000`
- All the elements of `pushed` are unique.
- `popped.length == pushed.length`
- `popped` is a permutation of `pushed`.

## Approach Explanation

We can simulate the stack push and pop operations:
1. Initialize an empty stack `st` and a pointer `j = 0` to point to the current element in the `popped` array.
2. Iterate through each element `x` in the `pushed` array.
3. Push `x` onto the stack `st`.
4. While the stack is not empty and the top of the stack matches `popped[j]`, we have found a valid sequence to pop. We pop the element from the stack and increment `j`.
5. Finally, if the stack is completely empty after iterating through all pushes and matched pops, it means the sequence is valid. Return `true` if the stack is empty, otherwise `false`.
