class Solution {
    void solve(int idx, vector<int> &nums, vector<vector<int>> &res){
        if(idx == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){

            swap(nums[idx],nums[i]);//DO
            solve(idx+1,nums,res);//EXPLORE
            swap(nums[idx],nums[i]);//UNDO

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        solve(0,nums,res);

        return res;
    }
};