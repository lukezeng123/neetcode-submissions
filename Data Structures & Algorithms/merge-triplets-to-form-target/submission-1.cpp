class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int meow1 = 0;
        int meow2 = 0;
        int meow3 = 0;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] &&  triplets[i][2] <= target[2]) {
                meow1 = 1;
            }
            if (triplets[i][1] == target[1] && triplets[i][0] <= target[0] &&  triplets[i][2] <= target[2]) {
                meow2 = 1;
            }
            if (triplets[i][2] == target[2] && triplets[i][1] <= target[1] &&  triplets[i][0] <= target[0]) {
                meow3 = 1;
            }
        }
        return meow1 && meow2 && meow3;
    }
};
