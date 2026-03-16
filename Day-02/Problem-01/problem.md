# 191. Number of 1 Bits

**Platform:** LeetCode
**Problem Link:** [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

## Problem Statement

Given a positive integer `n`, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

## Example Input/Output

**Example 1:**
**Input:** `n = 11`
**Output:** `3`
**Explanation:** The input binary string `1011` has a total of three set bits.

**Example 2:**
**Input:** `n = 128`
**Output:** `1`
**Explanation:** The input binary string `10000000` has a total of one set bit.

**Example 3:**
**Input:** `n = 2147483645`
**Output:** `30`
**Explanation:** The input binary string `1111111111111111111111111111101` has a total of thirty set bits.

## Constraints

- `1 <= n <= 2^31 - 1`

## Approach Explanation

We can solve this problem by repeatedly applying a bitwise operation:
1. Initialize a counter `cnt` to 0.
2. While `n` is greater than 0:
   - Check if the least significant bit (LSB) is 1 using `n & 1`. If it is, increment `cnt`.
   - Right-shift `n` by 1 (`n >> 1`) to process the next bit.
3. Once `n` becomes 0, all bits have been processed. Return `cnt`.

This approach ensures that we check exactly 32 bits (at most) out of the integer representation.
