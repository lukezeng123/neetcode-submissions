class MaxStack {
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

    vector<pair<int,int>> v;
    unordered_set<int> del;
    int cnt  =0;
    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        // list vector
        v.push_back({x,cnt});
        pq.push({x,cnt++});
    }
    
    int pop() {
        while (!v.empty() && del.contains(v.back().second)) {
            del.erase(v.back().second);
            v.pop_back();
        }
        del.insert(v.back().second);
        int val = v.back().first;
        v.pop_back();
        return val;
    }
    
    int top() {
        while (!v.empty() && del.contains(v.back().second)) {
            del.erase(v.back().second);
            v.pop_back();
        }
        return v.back().first;
    }
    
    int peekMax() {
        // heap
        while (!pq.empty() && del.contains(pq.top().second) > 0) {
            del.erase(pq.top().second);
            pq.pop();
        }
        return pq.top().first;
    }
    
    int popMax() {
        // heap
         while (!pq.empty() && del.contains(pq.top().second) > 0) {
            del.erase(pq.top().second);
            pq.pop();
        }
        int val = pq.top().first;
        del.insert(pq.top().second);
        pq.pop();
        return val;
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
