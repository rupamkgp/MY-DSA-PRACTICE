#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while (i < chars.size()) {
            int count = 1;
            while (i + 1 < chars.size() && chars[i] == chars[i+1]) {
                i++;
                count++;
            }
            chars[j++] = chars[i];
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) chars[j++] = c;
            }
            i++;
        }
        return j;
    }
};

int main() {
    return 0;
}
