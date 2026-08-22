class Solution {
public:
    bool checkDivisibility(int n) {
        if(n == 0) return true;
        int sum = 0;
        int product = 1;
        int org = n;
        int digit = 0;
        while(n>0){
            digit = n % 10;
            sum = sum + digit;
            product = product * digit;
            n = n/10;
        }
        int total = sum + product;
        if(org % total == 0) return true;
        return false;
    }
};