class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        map<int, int> pos_to_idx;


        for (int i = 0; i < n; ++i) {
            pos_to_idx[position[i]] = i;
        }

        int fleets = 0;
        double last = -1.0; 
        map<int ,int>::reverse_iterator it;
        for (it = pos_to_idx.rbegin(); it != pos_to_idx.rend(); ++it) {
            double time_taken = (target - it->first) / (speed[it->second] * 1.0);
            if (time_taken > last) {
                fleets++;
                last = time_taken;
            }
        }
        return fleets;
    }
};
