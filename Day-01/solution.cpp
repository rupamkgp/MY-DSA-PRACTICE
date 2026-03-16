#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}
    
    // Time Complexity: O(N) where N is the number of elements in the stack
    // Space Complexity: O(N) for using two queues
    void push(int x) {
        // Move all elements from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element to empty q1 (becomes the new top)
        q1.push(x);

        // Move elements back from q2 to q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int pop() {
        int val = q1.front();
        q1.pop(); // Removes the top element
        return val;
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int top() {
        return q1.front(); // Returns the top element
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool empty() {
        return q1.empty(); // Checks if stack is empty
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
