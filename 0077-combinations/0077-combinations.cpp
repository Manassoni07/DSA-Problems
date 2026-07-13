class Solution {
    void solve(int n, int k, vector<vector<int>> &result, vector<int> &curr, int i){
        // base case 
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }

        for(int j = i; j <= n - (k - curr.size()) + 1; j++){ //optmization for  Prune branches
            curr.push_back(j);
            solve(n,k,result,curr,j+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;

        solve(n,k,result,curr,1);

        return result;
    }
};