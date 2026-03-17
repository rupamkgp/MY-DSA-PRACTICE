# 66. Plus One

**Difficulty:** Easy
**Topics:** Array, Math

## Problem Statement

You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

**Example 2:**
```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

**Example 3:**
```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

## Constraints:
- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading 0's.

## Approach
- Iterate through the `digits` array starting from the least significant digit (end of the array) towards the most significant digit (beginning).
- If the current digit is less than 9, increment it by 1 and return the updated `digits` array immediately.
- If the current digit is 9, it becomes 0 (due to carry-over).
- If we finish the loop, it means all digits were 9 (e.g., [9, 9, 9] becomes [0, 0, 0]). In this case, we need to insert a 1 at the beginning of the array to account for the final carry.

## Complexity
- **Time Complexity:** O(N), where N is the number of digits in the array. In the worst case (e.g., all 9s), we iterate through all digits.
- **Space Complexity:** O(1) auxiliary space (or O(N) worst case if insertion at the beginning causes a reallocation).
