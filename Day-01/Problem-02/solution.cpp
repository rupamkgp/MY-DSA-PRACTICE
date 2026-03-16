#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}
    
    // Time Complexity: O(N) where N is the number of elements in the queue
    // Space Complexity: O(N) for using two stacks
    void push(int x) {
        // Move all elements from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element to s1 (will end up at the bottom)
        s1.push(x);

        // Move all elements back from s2 to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int pop() {
        int val = s1.top();
        s1.pop(); // Removes the front element
        return val;
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int peek() {
        return s1.top(); // Returns the front element
    }
    
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool empty() {
        return s1.empty(); // Checks if queue is empty
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
