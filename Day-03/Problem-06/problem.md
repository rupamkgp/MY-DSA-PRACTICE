# 128. Longest Consecutive Sequence

**Difficulty:** Medium
**Topics:** Array, Hash Table, Union Find

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in `O(n)` time.

**Example 1:**
```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**
```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**Example 3:**
```
Input: nums = [1,0,1,2]
Output: 3
```

## Constraints:
- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Approach
- We use an `unordered_set` (hash table) to store all the numbers. This allows for O(1) average time complexity for lookups.
- Iterate through the set. For each number, we check if it's the start of a sequence.
- A number is the start of a sequence if its previous consecutive number (`num - 1`) is not present in the set.
- If it is the start, we start counting upwards (`num + 1`, `num + 2`, etc.) by checking if those numbers exist in the set. We keep increasing the `length` as long as consecutive numbers are found.
- Keep track of the maximum `length` found so far in the `longest` variable.

## Complexity
- **Time Complexity:** O(N). Although there's a nested `while` loop, the inner loop only runs when a new sequence is found. Each element is visited at most twice (once in the outer sequence check and once in the inner inner while loop). Thus the time complexity is strictly linear, O(N).
- **Space Complexity:** O(N) to store the elements in the `unordered_set`.
