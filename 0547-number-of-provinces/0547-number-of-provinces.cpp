class Solution {
    void DFS(int u, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[u] = true;

        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[u][v] == 1 && !visited[v]) {
                DFS(v, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // here isConnected is nothing but adj[] 
        int n = isConnected.size();
        vector<bool> visited(n,false);

        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                DFS(i,isConnected,visited);
            }
        }

        return count;
    }
};