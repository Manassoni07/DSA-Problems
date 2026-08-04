class Solution {
    vector<int> topoSortCheck(int n, unordered_map<int, vector<int>>& adj,
                              vector<int>& indegree) {
        vector<int> ans;
        // Kahn's Algo

        queue<int> q;

        // now we fill 0 degree ele

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // now simple Bfs

        while (!q.empty()) {
            int u = q.front();
            // toposort order
            ans.push_back(u);
            q.pop();

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);

                }
            }
        }

        // now cycle detection

        if (ans.size() == n)
            return ans;

        return {};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& vec : prerequisites) {
            // b -> a
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSortCheck(numCourses, adj, indegree);
    }
};