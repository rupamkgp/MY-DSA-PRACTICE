#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> count(26, 0);
        for (char c : s1) count[c - 'a']++;
        int left = 0, right = 0, required = s1.length();
        while (right < s2.length()) {
            if (count[s2[right++] - 'a']-- > 0) required--;
            if (required == 0) return true;
            if (right - left == s1.length() && count[s2[left++] - 'a']++ >= 0) required++;
        }
        return false;
    }
};

int main() {
    return 0;
}
