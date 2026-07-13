class Solution {
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int idx){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        // Choice 1: Don't Pick the current element
        solve(nums, res, curr, idx + 1);
        
        // Choice 2: Pick the current element
        curr.push_back(nums[idx]);
        solve(nums, res, curr, idx + 1);
        
        // Backtracking step: Remove the element before returning to the previous state
        curr.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums,res,curr,0);

        return res;
    }
};