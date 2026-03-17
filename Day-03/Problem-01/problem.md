# 344. Reverse String

**Difficulty:** Easy
**Topics:** Two Pointers, String

## Problem Statement

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with `O(1)` extra memory.

**Example 1:**
```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**
```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

## Constraints:
- `1 <= s.length <= 10^5`
- `s[i]` is a printable ascii character.

## Approach: Two Pointers
- We use two pointers, `i` starting at the beginning `0` and `n` starting at the end `s.size() - 1`.
- In a loop, we swap the characters at `i` and `n`.
- Then, we increment `i` and decrement `n`.
- The loop continues as long as `i < n`.
- This approach reverses the array in-place with O(1) extra space.

## Complexity
- **Time Complexity:** O(N), where N is the length of the string `s`. We iterate through half of the characters in the string to perform the swaps.
- **Space Complexity:** O(1), as we only use a few integer variables (`i`, `n`) to keep track of indices, meaning the extra space required is constant regardless of the input size.
