class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;
        int pro = 1;
        while(ans > 0){
            int dig = ans % 10;
            pro = pro * dig;
            ans /= 10;
        }
        if(pro % t == 0) return n;

        return smallestNumber(n+1,t);
    }
};