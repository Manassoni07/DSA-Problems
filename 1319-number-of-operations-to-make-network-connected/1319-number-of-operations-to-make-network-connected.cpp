class Solution {
public:
    // find and union function
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);

        return parent[i];
    }

    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);

        if (p_x != p_y) {
            if (rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if (rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n -1) return -1;

        //initialize parent and rank
        parent.resize(n);// there are 26 letters
        rank.resize(n,0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        // now we sure that ans exists 

        int components = n;

        for(auto &vec : connections){
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0],vec[1]);
                components--;
            }
        }

        // now ans is 
        return components - 1;
    }
};