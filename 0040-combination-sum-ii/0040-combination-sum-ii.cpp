class Solution {
    void solve(vector<vector<int>> &res, vector<int> &curr, vector<int>& candidates, int target, int idx){
        //edge case {100,2} target = 1  -> 100 - 1 = -99 so we start with wrong path so we return
         
        if(target < 0) return;

        if(target == 0){
            res.push_back(curr);
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx &&(candidates[i] == candidates[i-1])){
                continue;
            }
            curr.push_back(candidates[i]); // DO
            solve(res, curr, candidates, target - candidates[i], i + 1);// WE Explore
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(candidates.begin(),candidates.end());

        solve(res,curr,candidates,target,0);

        return res;
    }
};