class MinStack {
    stack<long long>s;
    long long mini;
public:
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        long long v= (long long) val;
        if(s.empty()){
            mini=v;
            s.push(v);
        }else{
            if(v<mini){
                s.push(2*v-mini);
                mini=v;
            }else{
                s.push(v);
            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        long long x=s.top();
        s.pop();
        if(x<mini){
            mini=2*mini-x;
        }
    }
    
    int top() {
        long long x=s.top();
        if(mini<x){
            return int(x);
        }
        return int(mini);
    }
    
    int getMin() {
        return int(mini);
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