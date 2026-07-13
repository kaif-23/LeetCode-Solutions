class MinStack {
public:
  stack<int>st1;
  stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        st1.push(value);
        if (minSt.empty() || value <= minSt.top())
            minSt.push(value);
    }
    
    void pop() {
        if(st1.empty())return;
       int topV=st1.top();
        st1.pop();
        if(topV==minSt.top()){
            minSt.pop();
        }
    }
    
    int top() {
       return st1.top();
    }
    
    int getMin() {
       return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */