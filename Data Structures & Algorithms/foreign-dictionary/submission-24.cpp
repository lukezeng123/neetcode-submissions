class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (int i = 0; i < words.size(); i++) {
            for (auto c: words[i]) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            string w1 = words[i - 1];
            string w2 = words[i];
            int minLen = min(w1.size(),w2.size());
            if (w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)) {
                cout << "meow" << endl;
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].count(w2[j]) == 0) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        string res;
        queue<int> q;

        for (auto [c, n] : indegree) {
            cout << c << " " << n << endl;
            if (n == 0) {
                q.push(c);
            }
        } 

        while (!q.empty()) {
            char char_ = q.front();
            q.pop();
            res += char_;
            for (char neighbour : adj[char_]) {
                if (--indegree[neighbour] == 0) {
                    q.push(neighbour);
                    cout << neighbour << endl;
                }
            }
        }
        cout << res;

        return res.size() == indegree.size() ? res : "";
    }
};
