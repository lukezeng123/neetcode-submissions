class Twitter {
    int count;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<vector<int>>> posts;
public:
    Twitter() : count(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(compare)> minHeap(compare);
        follows[userId].insert(userId);
        for (int followeeId : follows[userId]) {
            if (posts.count(followeeId)) {
                const vector<vector<int>>& tweets = posts[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0],tweets[index][1], followeeId, index});
            }
        }
        while (!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const vector<int>& tweet = posts[curr[2]][index - 1];
                minHeap.push({tweet[0],tweet[1],curr[2],index - 1});
            }
            
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
