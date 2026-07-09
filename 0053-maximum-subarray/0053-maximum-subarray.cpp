class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int best_ending = 0;

        for(int i = 0; i < nums.size(); i++){
            int v1 = best_ending + nums[i];
            int v2 = nums[i];
            best_ending = max(v1,v2);
            ans = max(best_ending,ans);
        }
        
        return ans;
    }
};