class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inputStack.push(x);
    }
    
    /** Removes the element from the front of queue and returns that element. */
    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }
    
    /** Get the front element. */
    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        
        return outputStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};