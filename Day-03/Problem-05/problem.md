# 27. Remove Element

**Difficulty:** Easy
**Topics:** Array, Two Pointers

## Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

1.  Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
2.  Return `k`.

**Example 1:**
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## Constraints:
- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## Approach
- Use an index `k` to keep track of the position where the next valid element (not equal to `val`) should be placed. Initialize `k = 0`.
- Iterate through the array `nums` with another index `i`.
- If `nums[i]` is not equal to `val`, copy `nums[i]` to `nums[k]` and increment `k`.
- If `nums[i]` is equal to `val`, just continue to the next element.
- The first `k` elements of `nums` will contain all the elements not equal to `val`, and `k` will be the new length.

## Complexity
- **Time Complexity:** O(N), where N is the length of `nums`. Both `i` and `k` traverse at most N steps.
- **Space Complexity:** O(1), as modifications are done in-place and only constant extra space for variables `n` and `k` is used.
