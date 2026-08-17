class Solution {
    void DFS(unordered_map<int,vector<int>> &adj, vector<int>& visited, int s) {
        if (visited[s] == true)
            return;

        visited[s] = true;

        for (int& v : adj[s]) {
            if (!visited[v]) {
                DFS(adj, visited, v);
            }
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // int n = edges.size();

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dfs from source

        vector<int> visited(n, false);

        DFS(adj, visited, source);

        if (!visited[destination])
            return false;

        return true;
    }
};