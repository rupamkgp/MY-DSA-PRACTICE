#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Time Complexity: O(N) where N is the length of the pushed array
    // Space Complexity: O(N) for the stack
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // Pointer for the popped array

        for(int x : pushed) {
            st.push(x); // Push the current element onto the stack
    
            // Check if top of the stack matches the current popped element
            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        // If stack is empty, it means all push and pop operations were successfully simulated
        return st.empty();
    }
};
