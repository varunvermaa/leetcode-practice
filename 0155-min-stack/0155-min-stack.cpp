class MinStack {
public:
    stack<long> s;
    long min;
    

    MinStack() {
        
    }
    
    void push(int x) {
        long val = (long)x;
        if(s.empty()){
            s.push(val);
            min = val;
        }
        else if(val>=min) s.push(val);
        else {
            s.push(2*val - min);
            min = val;
        }
    }
    
    void pop() {
        if(s.empty()) return;
        else if(s.top()>= min) s.pop();
        else{
            min = 2*min - s.top();
            s.pop();
        }
        
    }
    
    int top() {
        if(s.empty()) return 0;
        long a = s.top();
        if(s.top() >= min) return a;
        else return (int)min;
        return 1;
    }
    
    int getMin() {
        return (int)min;
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