#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top(); st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    auto res = sol.dailyTemperatures(temps);
    cout << res[0] << endl; // Expected: 1
    return 0;
}
