class CustomStack {
public:
    int mx = 0;
    stack<int> stk;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(stk.size() < mx) stk.push(x);
    }
    
    int pop() {
        if(stk.size()) {
            int value = stk.top();
            stk.pop();
            return value;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int cnt = 0;
        stack<int> temp;
        while(stk.size()) {
            temp.push(stk.top());
            stk.pop();
        }
        
        while(temp.size()) {
            int value = temp.top();
            if(k) {
                value += val;
                k--;
            }
            temp.pop();
            stk.push(value);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
