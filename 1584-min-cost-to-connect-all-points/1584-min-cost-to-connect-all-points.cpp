class Solution {
public:
    typedef pair<int, int> P;

    int primsAlgo(vector<vector<P>>& adj, int n) {
        int sum = 0;
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});

        vector<bool> inMST(n, false);

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int w = p.first;
            int node = p.second;

            if (inMST[node])
                continue;

            inMST[node] = true;

            sum += w;

            for (auto& temp : adj[node]) {
                int v = temp.first;
                int n_w = temp.second;

                if (inMST[v] == false) {
                    pq.push({n_w, v});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // first we create graph
        vector<vector<P>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return primsAlgo(adj, n);
    }
};