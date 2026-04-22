class MaxStack {
    // popMax
    // list as stack
    int cnt;
    stack<pair<int,int>> st;
    priority_queue<pair<int,int>> heap;
    unordered_set<int> removed;
    // track max with multiset and list iterator
    
public:
    MaxStack() {
        cnt = 0;
    }
    
    void push(int x) {
        st.push({x,cnt});
        heap.push({x,cnt});
        cnt++;
    }
    
    int pop() {
        while (removed.count(st.top().second)) {
            st.pop();
        }
        const pair<int,int> p = st.top();
        st.pop();
        removed.insert(p.second);
        return p.first;
    }
    
    int top() {
        while (removed.count(st.top().second)) {
            st.pop();
        }
        return st.top().first;
    }
    
    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }
    
    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        const pair<int,int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
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
