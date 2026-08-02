class Solution {
public:
    bool checkGoodInteger(int n) {
        int dig = 0;
        int sq = 0;

        while(n > 0){
            int rem = n % 10;
            dig = dig + rem;
            sq = sq + (rem * rem);
            n = n/10;
        }
        if(sq - dig >= 50) return true;

        return false;
    }
};