# 231. Power of Two

**Platform:** LeetCode
**Problem Link:** [Power of Two](https://leetcode.com/problems/power-of-two/)

## Problem Statement

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2^x`.

## Example Input/Output

**Example 1:**
**Input:** `n = 1`
**Output:** `true`
**Explanation:** `2^0 = 1`

**Example 2:**
**Input:** `n = 16`
**Output:** `true`
**Explanation:** `2^4 = 16`

**Example 3:**
**Input:** `n = 3`
**Output:** `false`

## Constraints

- `-2^31 <= n <= 2^31 - 1`

## Approach Explanation

We use bitwise properties to verify if a number is a power of 2 efficiently:
1. If `n <= 0`, it is definitely not a power of 2, so return `false`.
2. A number `n` that is a power of 2 has exactly one bit set to `1` in its binary representation.
3. Therefore, `n - 1` will have all the bits starting from the correct rightmost `1` flipped.
4. Performing a bitwise AND `(n & (n - 1))` removes the lowest set bit. If `n` was a power of two, there is exactly one set bit, so `(n & (n - 1))` will be exactly `0`.
