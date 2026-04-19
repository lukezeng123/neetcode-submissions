class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> posts;
public:
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = posts[userId];
        for (int fid : follows[userId]) {
            feed.insert(feed.end(), posts[fid].begin(), posts[fid].end());
        }

        sort(feed.begin(), feed.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        vector<int> res;
        for (int i = 0; i < min(10,(int)feed.size()); i++) {
            res.push_back(feed[i].second);
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
