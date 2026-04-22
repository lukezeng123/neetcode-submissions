class MaxStack {
    // popMax
    // current max -> remove for multiset

    // keep track of current max and position in stack

    // list as stack
    list<int> st;
    // track max with multiset and list iterator
    map<int, list<list<int>::iterator>> m;
public:
    MaxStack() {
    }
    
    void push(int x) {
        st.push_front(x);
        m[x].push_front(st.begin());
    }
    
    int pop() {
        int x = st.front();
        m[x].pop_front();
        if (m[x].empty()) m.erase(x);
        st.pop_front();
        return x;
    }
    
    int top() {
        return st.front();
    }
    
    int peekMax() {
        return prev(m.end())->first;
    }
    
    int popMax() {
        int x = prev(m.end())->first;
        auto it = m[x].front();
        st.erase(it);
        m[x].pop_front();
        if (m[x].empty()) m.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
