class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack() {

    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(val);

            minstk.push(val);
        } else {
            stk.push(val);

            minstk.push(min(val, minstk.top()));
        }
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
       return minstk.top();
    }
};
