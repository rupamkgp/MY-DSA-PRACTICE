# 58. Length of Last Word

**Difficulty:** Easy
**Topics:** String

## Problem Statement

Given a string `s` consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

**Example 1:**
```
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

**Example 2:**
```
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

**Example 3:**
```
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

## Constraints:
- `1 <= s.length <= 10^4`
- `s` consists of only English letters and spaces `' '`.
- There will be at least one word in `s`.

## Approach
- Iterate through the string from the end to the beginning (right to left).
- Use a variable `len` to keep track of the length of the last word.
- Ignore trailing spaces.
- Once a non-space character is found, increment `len` for each subsequent non-space character.
- Stop when the next space character is encountered after we have started counting the word length (`len > 0`).

## Complexity
- **Time Complexity:** O(N), where N is the length of the string `s`. In the worst case, we might iterate through the entire string.
- **Space Complexity:** O(1), as we only use a constant amount of extra space for loop variables (`len`, `i`).
