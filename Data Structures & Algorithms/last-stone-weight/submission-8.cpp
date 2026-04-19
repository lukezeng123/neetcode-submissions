class Solution {
public:
    priority_queue <int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        int sum = 0;
        while (!pq.empty()) {
            int s1 = pq.top();
            pq.pop();
            if (pq.empty()) {
                sum += s1;
                break;
            }
            int s2 = pq.top();
            pq.pop();
            if (s1 == s2) continue;
            pq.push(abs(s1 - s2));
        }
        return sum;
    }
};
