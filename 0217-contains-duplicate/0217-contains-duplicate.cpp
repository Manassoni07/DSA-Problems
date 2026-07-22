class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num : nums){
            if(m[num] >= 1) return true;
            m[num]++;
        }
        return false;
    }
};