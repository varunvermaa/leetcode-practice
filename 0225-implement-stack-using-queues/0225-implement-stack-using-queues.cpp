class MyStack {

    deque<int> d;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        d.push_front(x);
    }
    
    int pop() {
        int a = d.front();
       d.pop_front();
       return a;
    }
    
    int top() {
       return d.front();
    }
    
    bool empty() {
        return d.empty();
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