# 28. Find the Index of the First Occurrence in a String

**Difficulty:** Easy
**Topics:** Two Pointers, String, String Matching

## Problem Statement

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**
```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

**Example 2:**
```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

## Constraints:
- `1 <= haystack.length, needle.length <= 10^4`
- `haystack` and `needle` consist of only lowercase English characters.

## Approach
- Use the built-in C++ string function `std::string::find()`.
- Let `idx = haystack.find(needle)`.
- If `needle` is found, `find` returns the index of its first occurrence. Otherwise, it returns `std::string::npos`.
- Since `find` returns an unsigned value (`size_t`) or a specific constant indicating failure, casting it to an integer correctly translates `std::string::npos` (typically the maximum possible value for `size_t`) to `-1`.

## Complexity
- **Time Complexity:** O(N * M), where N is the length of `haystack` and M is the length of `needle`. The `std::string::find()` function in C++ typically has a worst-case time complexity of O(N * M), although naive search might be O((N-M+1)*M). Modern implementations might optimize this to O(N + M) using algorithms like KMP or Boyer-Moore.
- **Space Complexity:** O(1), as `find` operates in-place without using any additional data structures whose size depends on the input.
