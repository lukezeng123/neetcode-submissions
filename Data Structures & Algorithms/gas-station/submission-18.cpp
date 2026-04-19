class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int tmp = n;
            int idx = i;
            int g = 0;
            while (tmp--) {
                g += gas[idx % n];
                g -= cost[idx % n];
                cout << g << " " << tmp << endl;
                if (g < 0) break;
                idx++;
            }
            cout << endl;
            if (tmp < 0) return i;
            
        }
        return -1;
    }
};
