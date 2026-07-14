class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr,
               int idx) {
        if (idx >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(nums, res, curr, idx + 1);

        curr.pop_back();
        // skip duplicates before not take branch
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        solve(nums, res, curr, idx + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());

        solve(nums, res, curr, 0);

        return res;
    }
};