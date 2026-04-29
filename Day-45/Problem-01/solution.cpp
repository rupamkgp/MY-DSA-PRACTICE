#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

int main() {
    Solution sol;
    cout << sol.fib(4) << endl; // Expected: 3
    return 0;
}
