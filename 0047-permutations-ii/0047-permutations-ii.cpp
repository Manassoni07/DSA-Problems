class Solution {
    void solve(int idx, vector<int>& nums, vector<vector<int>> &res){
         if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> lookup; // Tracks elements already placed at position 'idx'
        
        for (int i = idx; i < nums.size(); i++) {
            // If we already used this number at 'idx' in this level, skip it
            if (lookup.count(nums[i])) continue; 
            
            lookup.insert(nums[i]);
            
            swap(nums[idx], nums[i]);  // DO
            solve(idx + 1, nums, res); // EXPLORE
            swap(nums[idx], nums[i]);  // UNDO
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        solve(0,nums,res);

        return res;
    }
};