class Solution {
    typedef pair<int, int> edge;
    static constexpr int N = 1005;
    static constexpr int INF = 50000;
    vector<edge> adj[N];
    int dist[N];
public:
    void dijkstra(int src) {
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        fill(dist, dist + N, INF);
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int w = cur.first;
            int v = cur.second;
            if (dist[v] == INF) {
                dist[v] = w;
                for (auto e : adj[v]) {
                    pq.emplace(e.first + w, e.second);
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto t : times) {
            adj[t[0]].emplace_back(t[2], t[1]);
        }
        dijkstra(k);
        int mmax = -1;
        for (int i = 1; i <= n; i++) {
            mmax = max(mmax, dist[i]);
        }
        return mmax == INF ? -1 : mmax;
    }
};
