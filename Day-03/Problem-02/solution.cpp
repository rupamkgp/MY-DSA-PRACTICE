#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i>=0 ; i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;

        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> digits1 = {1, 2, 3};
    vector<int> res1 = sol.plusOne(digits1);
    cout << "Example 1 Output: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> res2 = sol.plusOne(digits2);
    cout << "Example 2 Output: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    vector<int> digits3 = {9};
    vector<int> res3 = sol.plusOne(digits3);
    cout << "Example 3 Output: ";
    for (int num : res3) cout << num << " ";
    cout << endl;

    return 0;
}
