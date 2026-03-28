#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if (nn < 0) {
            nn = -nn;
            x = 1.0 / x;
        }
        double ans = 1.0;
        while (nn > 0) {
            if (nn % 2 != 0) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
