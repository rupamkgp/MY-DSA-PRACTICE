#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        
    }
};

int main() {
    Solution sol;
    cout << "Example 1 Output: " << sol.strStr("sadbutsad", "sad") << endl;
    cout << "Example 2 Output: " << sol.strStr("leetcode", "leeto") << endl;
    return 0;
}
