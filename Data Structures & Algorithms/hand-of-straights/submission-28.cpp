class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> freq;
        for (auto num : hand) {
            if (freq.find(num) == freq.end()) {
                pq.push(num);
            }
            freq[num]++;
        }

        while (!pq.empty()) {
            cout << "poop" << endl;
            int start = pq.top();
            cout << start << endl;
            if(!--freq[start]) {
                cout << "popping " << pq.top() << endl;
                pq.pop();

            }
            int group_size = 1;
            int cur = start;
            while (group_size != groupSize) {
                // cout << cur + 1 << endl;
                if (freq[cur + 1] <= 0) {
                    return false;
                } else {
                    cout << "removing " << cur + 1 << endl; 
                    if (!--freq[cur + 1]) {
                        cout << "popping " << pq.top() << endl;
                        pq.pop();
                    }
                    cur = cur + 1;
                    group_size++;
                }
            }
        }
        return true;
    }
};
