class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        // now make graph

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<bool> faulty(n, false);

        // bfs

        // we start traversal from k
        q.push(k);
        faulty[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : adj[u]) {
                indegree[v]--;
                if (!faulty[v]) {
                    q.push(v);
                    faulty[v] = true;
                }
            }
        }
        // now we remove faulty node from ans
        vector<int> ans;
        bool canbeRemoved = true;

        for (int i = 0; i < n; i++) {
            if (indegree[i] > 0 && faulty[i]) {
                canbeRemoved = false;
                break;
            }
            if (!faulty[i])
                ans.push_back(i);
        }

        if (!canbeRemoved) {
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                vec.push_back(i); // 1 .... n -1
            }

            return vec;
        }

        return ans;
    }
};