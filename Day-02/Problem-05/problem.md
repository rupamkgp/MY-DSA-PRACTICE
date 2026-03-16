# 217. Contains Duplicate

**Platform:** LeetCode
**Problem Link:** [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

## Problem Statement

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Example Input/Output

**Example 1:**
**Input:** `nums = [1,2,3,1]`
**Output:** `true`
**Explanation:** The element `1` occurs at indices `0` and `3`.

**Example 2:**
**Input:** `nums = [1,2,3,4]`
**Output:** `false`
**Explanation:** All elements are distinct.

**Example 3:**
**Input:** `nums = [1,1,1,3,3,4,3,2,4,2]`
**Output:** `true`

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Approach Explanation

We use a Hash Set (Unordered Set in C++) to keep track of elements we've already seen:
1. Initialize an empty hash set `st` to store the unique values.
2. Iterate through each element `x` in the array `nums`.
3. If `x` is already present inside `st` (we can check it using `st.count(x)`), it means we found a duplicate, so return `true`.
4. Otherwise, insert `x` into `st`.
5. If we complete the loop returning nothing, it implies all elements were distinct, so return `false`.
