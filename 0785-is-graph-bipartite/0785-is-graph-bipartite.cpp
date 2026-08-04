class Solution {
    bool solve(vector<vector<int>>& graph, vector<int>& color, int currColor,
               int curr) {
        color[curr] = currColor;

        for (int& v : graph[curr]) {
            if (color[v] == color[curr])
                return false;

            if (color[v] == -1) {
                int Vcolor = 1 - color[curr];

                if (solve(graph, color, Vcolor, v) == false)
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        int currColor = 0;
        for (int u = 0; u < n; u++) {
            if (color[u] == -1) {

                if (solve(graph, color, currColor, u) == false)
                    return false;
            }
        }

        return true;
    }
};