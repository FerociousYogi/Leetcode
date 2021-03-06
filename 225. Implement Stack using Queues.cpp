class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    
    MyStack() {
        queue<int> q1, q2;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty()) q1.swap(q2);
        
        while(q1.size() > 1) {
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        int temp = q1.front();
        q1.pop();
        
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) q1.swap(q2);
        
        while(q1.size() > 1) {
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
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