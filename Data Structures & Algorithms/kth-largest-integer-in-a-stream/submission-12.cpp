class KthLargest {
    priority_queue <int,vector<int>, greater<int>> topk;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            topk.push(nums[i]);
            if (topk.size() > k) {
                topk.pop();
            }
        }
    }
    
    int add(int val) {
        topk.push(val);
        if (topk.size() > k) {
            topk.pop();
        }
        return topk.top();
    }
};
