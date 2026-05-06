#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if (s == "+") st.push(op1 + op2);
                else if (s == "-") st.push(op1 - op2);
                else if (s == "*") st.push(op1 * op2);
                else st.push(op1 / op2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution sol;
    cout << sol.evalRPN(tokens) << endl; // Expected: 9
    return 0;
}
