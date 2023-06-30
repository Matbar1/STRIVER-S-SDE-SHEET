class MyStack {
private:
    std::queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};