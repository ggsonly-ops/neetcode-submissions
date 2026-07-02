class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0) q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (int next : adj[node]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }

        return topo.size() == numCourses ? topo : vector<int>{};
    }
};