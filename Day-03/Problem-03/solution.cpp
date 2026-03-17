#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len = 0;

        for(int i = n-1; i>=0 ;i--){
            if(s[i]==' ' && len>0) break;
            if(s[i]!=' ') len++;
        }
        return len;
    }
};

int main() {
    Solution sol;
    cout << "Example 1 Output: " << sol.lengthOfLastWord("Hello World") << endl;
    cout << "Example 2 Output: " << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << "Example 3 Output: " << sol.lengthOfLastWord("luffy is still joyboy") << endl;

    return 0;
}
