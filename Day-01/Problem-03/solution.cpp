#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    // Stack to store pairs of {value, current_minimum}
    stack<pair<int,int>> s;

    MinStack() {}
    
    // Time Complexity: O(1)
    // Space Complexity: O(N) where N is number of elements in the stack
    void push(int val) {
        if(s.empty()) {
            s.push({val, val});
        } else {
            // New minimum is the min of current value and the previous minimum
            int minval = min(val, s.top().second);
            s.push({val, minval});
        }
    }
    
    // Time Complexity: O(1)
    void pop() {
        s.pop();
    }
    
    // Time Complexity: O(1)
    int top() {
        return s.top().first; // The original value is stored in 'first'
    }
    
    // Time Complexity: O(1)
    int getMin() {
        return s.top().second; // The minimum value at this state is stored in 'second'
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
