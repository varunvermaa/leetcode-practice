class MyQueue {
public:
stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
        bottom(s, x);
    }
    
    int pop() {
        int a = s.top();
        s.pop();
        return a;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }

    void bottom(stack<int>& s, int a){
        if(s.empty()){
            s.push(a);
            return;
        }
        int top = s.top();
        s.pop();
        bottom(s, a);
        s.push(top);   

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