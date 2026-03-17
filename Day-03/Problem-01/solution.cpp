#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        //Two Pointers

        int n = s.size()-1;
        int i = 0;
        while(i<n){
          swap(s[i],s[n]);
          n--;
          i++;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s1);
    cout << "Reversed Example 1: ";
    for (char c : s1) cout << c << " ";
    cout << endl;

    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(s2);
    cout << "Reversed Example 2: ";
    for (char c : s2) cout << c << " ";
    cout << endl;

    return 0;
}
