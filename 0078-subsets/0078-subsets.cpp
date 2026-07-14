class Solution {
    void solve(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int idx){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(nums, res, curr, idx + 1);

        curr.pop_back();
        solve(nums, res, curr, idx + 1);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums,res,curr,0);

        return res;
    }
};