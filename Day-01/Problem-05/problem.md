# 136. Single Number

**Platform:** LeetCode
**Problem Link:** [Single Number](https://leetcode.com/problems/single-number/)

## Problem Statement

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

## Example Input/Output

**Example 1:**
**Input:** `nums = [2,2,1]`
**Output:** `1`

**Example 2:**
**Input:** `nums = [4,1,2,1,2]`
**Output:** `4`

**Example 3:**
**Input:** `nums = [1]`
**Output:** `1`

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

## Approach Explanation

We use the bitwise XOR operation feature to solve this problem efficiently in linear time `O(N)` and constant space `O(1)`.

The properties of XOR operator (`^`) are:
1. `X ^ 0 = X` (Any number XORed with zero remains the same).
2. `X ^ X = 0` (Any number XORed with itself becomes zero).
3. XOR is associative and commutative.

Since every element except one appears exactly twice in the array, when we XOR all the numbers together, the numbers that appear twice will cancel each other out (yielding `0`), and the only number that does not cancel out will be our unique single number.
