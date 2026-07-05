class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> leaves;
        for (int node = 0; node < n; node++) {
            if (degree[node] == 1) {
                leaves.push(node);
            }
        }

        int remaining = n;
        vector<int> lastLayer;

        while (remaining > 2) {
            int leafCount = leaves.size();
            remaining -= leafCount;

            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        while (!leaves.empty()) {
            lastLayer.push_back(leaves.front());
            leaves.pop();
        }

        return lastLayer;
    }
};