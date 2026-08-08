class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        int num = n;

        while(num > 0){
            res += num & 1;
            num = num >> 1;
        }
    return res;
    }
};