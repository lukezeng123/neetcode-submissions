class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

        for (auto& p : points) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> n;
        while (!pq.empty()) {
            n.push_back(pq.top());
            pq.pop();
        }
        return n;
    }
};
