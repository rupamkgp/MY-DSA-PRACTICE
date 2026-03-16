# 1. Two Sum

**Platform:** LeetCode
**Problem Link:** [Two Sum](https://leetcode.com/problems/two-sum/)

## Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Example Input/Output

**Example 1:**
**Input:** `nums = [2,7,11,15], target = 9`
**Output:** `[0,1]`
**Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

**Example 2:**
**Input:** `nums = [3,2,4], target = 6`
**Output:** `[1,2]`

**Example 3:**
**Input:** `nums = [3,3], target = 6`
**Output:** `[0,1]`

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

## Approach Explanation

We use a Hash Map (Unordered Map in C++) to store elements as we iterate through the array:
1. Initialize an empty hash map `mp` to store the value of each element and its corresponding index.
2. Iterate through the array. For each element, compute `need = target - nums[i]`. This is the complement number we need to form the target sum.
3. Check if `need` already exists in the hash map.
   - If it does, we found our two numbers. Return the mapped index of `need` along with the current index `i`.
   - If it doesn't, insert the current element `nums[i]` and its index into the map.
4. By doing this in one pass, finding the two values becomes extremely fast and efficient, at the cost of additional memory linearly proportional to the size of the array.
