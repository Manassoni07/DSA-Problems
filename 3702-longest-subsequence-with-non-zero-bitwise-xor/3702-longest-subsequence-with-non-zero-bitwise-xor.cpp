class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot = 0, nonZero = 0;

        for (int& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }
};