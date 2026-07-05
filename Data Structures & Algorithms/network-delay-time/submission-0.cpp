class Solution {
#define P pair<int,int>
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& t : times) {
            int u = t[0], v = t[1], wt = t[2];
            adj[u].push_back({v, wt}); 
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue; // stale entry, skip

            for (auto& [adjNode, edgeWt] : adj[node]) {
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};