class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size()/2;
        int count = 0;
        for(int x : nums){
            if(x == nums[mid]) count++;
        }

        if(count == 1) return true;

        return false;
    }
};