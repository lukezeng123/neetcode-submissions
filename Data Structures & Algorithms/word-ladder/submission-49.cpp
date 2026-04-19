class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        unordered_map<string, vector<string>> mp;
        int m = beginWord.size();
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            words.insert(wordList[i]);
        }
        words.insert(beginWord);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string w = wordList[i];
                for (int k = 0; k < 26; k++) {
                    w[j] = 'a' + k;
                    if (w != wordList[i] && words.count(w) == 1) {
                        mp[w].push_back(wordList[i]);
                    }
                }
            }
        }
        for (int j = 0; j < m; j++) {
                string w = beginWord;
                for (int k = 0; k < 26; k++) {
                    w[j] = 'a' + k;
                    if (w != beginWord && words.count(w) == 1) {
                        mp[beginWord].push_back(w);
                    }
                }
            }

        
        for (auto [u, e]: mp) {
            for (auto v : e) {
                cout << u << " " << v << endl;
            }
        }
        unordered_map<string, int> dist, visited;
        const int INF = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            dist[wordList[i]] = INF;
            visited[wordList[i]] = 0;
        }
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        dist[endWord] = INF;
        
        while (!q.empty()) {
            string u = q.front();
            cout << u << endl;
            q.pop();
            
            for (auto v : mp[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if (dist[endWord] != INF) {
            return dist[endWord] + 1;
        }
        return 0;
    }
};
