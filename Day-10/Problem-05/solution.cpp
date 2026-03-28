#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), n);
        }
        return s;
    }
};

int main() {
    return 0;
}
