# 242. Valid Anagram

**Difficulty:** Easy
**Topics:** Hash Table, String, Sorting

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

**Example 1:**
```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**
```
Input: s = "rat", t = "car"
Output: false
```

## Constraints:
- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## Approach
- Step 1: Check lengths. If `s` and `t` have different lengths, they cannot be anagrams. Return `false` immediately.
- Step 2: Use an array `freq` of size 26 (since the strings consist only of lowercase English letters) to keep track of character frequencies.
- Iterate through string `s` and increment the count corresponding to each character in `freq`.
- Iterate through string `t` and decrement the count corresponding to each character in `freq`.
- Loop through the `freq` array. If any count is not `0`, it means `s` and `t` have a different number of some characters, so return `false`.
- If all counts are `0`, `t` is a valid anagram of `s`, so return `true`.

## Complexity
- **Time Complexity:** O(N), where N is the length of the string `s` (since length of `s` and `t` must be equal to reach the frequency counting). The approach iterates over both strings linearly and then transverses the fixed size array (size 26), which is O(1). Thus overall time is linear.
- **Space Complexity:** O(1), since the size of the array `freq` is constant (26) irrespective of the input lengths.
