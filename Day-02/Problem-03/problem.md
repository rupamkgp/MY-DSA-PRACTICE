# 268. Missing Number

**Platform:** LeetCode
**Problem Link:** [Missing Number](https://leetcode.com/problems/missing-number/)

## Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

## Example Input/Output

**Example 1:**
**Input:** `nums = [3,0,1]`
**Output:** `2`
**Explanation:** `n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. The missing number is `2`.

**Example 2:**
**Input:** `nums = [0,1]`
**Output:** `2`
**Explanation:** `n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. The missing number is `2`.

**Example 3:**
**Input:** `nums = [9,6,4,2,3,5,7,0,1]`
**Output:** `8`
**Explanation:** `n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. The missing number is `8`.

## Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are unique.

## Approach Explanation

We can use the properties of XOR to find the missing number in linear time and constant space:
1. Remember that `x ^ x = 0` and `x ^ 0 = x`.
2. Since the range is `[0, n]` and `nums` contains `n` elements, if we XOR all the expected numbers `0, 1, ..., n` together with all the actual elements in the array, all present numbers will appear twice and cancel each other out (yielding 0).
3. The only element that appears just once (the expected number that is missing in `nums`) will remain as the XOR sum.
4. Hence, initialize `ans = nums.size()`, then linearly traverse the array. For each element up to size, XOR current array element and its index `ans ^= (i ^ nums[i])`.
