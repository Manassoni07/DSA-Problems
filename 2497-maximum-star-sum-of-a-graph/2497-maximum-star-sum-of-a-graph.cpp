class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            vis[i] = 1;
            q.push(i);

            while(!q.empty()){
                vector<int> temp;
                int u = q.front(); q.pop();

                for(int v: adj[u]){
                    temp.push_back(vals[v]);
                    if(!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
                int sm = vals[u];
                sort(temp.begin(), temp.end(), greater<>());
                for(int i = 0; i < min((int)temp.size(), k); i++){
                    if(temp[i] < 0) break;
                    sm += temp[i];
                }
                ans = max(ans, sm);
            }
        }
        return ans;
    }
};