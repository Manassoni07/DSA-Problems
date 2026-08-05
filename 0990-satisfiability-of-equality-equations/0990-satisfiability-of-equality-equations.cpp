class Solution {
public:
    // find and union function 
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }


    bool equationsPossible(vector<string>& equations) {
        //initialize parent and rank
        parent.resize(26);// there are 26 letters
        rank.resize(26,0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

/*
        //  0 1 2 3 
        //  x = = y
        //  x ! = y
*/

        for(string &s : equations){
            // now we process == operation 
            if(s[1] == '='){
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        // now process != operation 

        for(string &s : equations){
            if(s[1] == '!'){
                char a = s[0];
                char b = s[3];

                int p1 = find(a - 'a');
                int p2 = find(b - 'a');

                if(p1 == p2) return false;

            }
        }

        return true;
    }
};