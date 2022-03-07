class MinStack {
public:
    stack<int> as,ms;
    MinStack() {
        
    }
    
    void push(int val) {
        ms.push(val);
        if(as.empty() || as.top() >= val) as.push(val);
    }
    
    void pop() {
        if(ms.top() == as.top()) as.pop();
        ms.pop();
    }
    
    int top() {
        return ms.top();
    }
    
    int getMin() {
        return as.top();
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