class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (m[key].empty() || m[key][0].first > timestamp) return "";
        vector<pair<int,string>> meow = m[key];
        int l = 0, r = meow.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2; 
            if (meow[mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return meow[l].second;

    }
};
