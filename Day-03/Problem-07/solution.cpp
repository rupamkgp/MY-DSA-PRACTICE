#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //base case 
      if(s.size()!=t.size()) return false;

      int freq[26]={0};

      for(char c: s){
        freq[c-'a']++;
      }

      for(char c: t){
        freq[c-'a']--;
      }

      for(int x : freq){
        if(x != 0) return false;
      }
     
     return true;
    }
};

int main() {
    Solution sol;
    cout << "Example 1 Output: " << (sol.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
    cout << "Example 2 Output: " << (sol.isAnagram("rat", "car") ? "true" : "false") << endl;
    return 0;
}
