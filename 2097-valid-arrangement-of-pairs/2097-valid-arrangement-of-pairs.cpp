class Solution {
    void DFS(vector<int> &eulerPath, int node, unordered_map<int,vector<int>> &adj){
        while (!adj[node].empty()) {
            int nextNode = adj[node].back();
            adj[node].pop_back();  // Remove the edge after visiting
            DFS(eulerPath,nextNode,adj);         // Recursive DFS call
        }
        eulerPath.push_back(node);  // Add node to Euler path after all edges are visited
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Heirholzer's algorithm 

        // step 1 we build adj list 

        unordered_map<int,vector<int>> adj;
        unordered_map<int, int> indeg, outdeg;

        for(auto &edge : pairs){
            int u = edge[0];
            int v = edge[1]; 

            adj[u].push_back(v);
            outdeg[u]++;
            indeg[v]++;
        }

        int startNode = pairs[0][0];

        for(auto &it : adj){
            int x = it.first;

            if(outdeg[x] - indeg[x] == 1){
                startNode = x;
                break;
            }
        }

        vector<int> eulerPath;

        DFS(eulerPath,startNode,adj);

        vector<vector<int>> ans;

        for(int i = eulerPath.size() - 1; i > 0; i--){
            ans.push_back({eulerPath[i],eulerPath[i-1]});
        }

        return ans;

    }
};