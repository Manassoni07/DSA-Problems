class Solution {
    bool topoSortCheck(int n, unordered_map<int,vector<int>>& adj,vector<int>& indegree){
        // Kahn's Algo

        queue<int> q;
        int count = 0;

        // now we fill o degree ele 

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }

        // now simple Bfs

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }

        // now cycle detection 

        if(count == n) return true;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // now make graph 
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &vec : prerequisites){
            // b -> a 
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            indegree[a]++;            
        }

        return topoSortCheck(numCourses,adj,indegree);
    }
};