class Solution {
    double ans(double x, long long N){

        if(N == 0) return 1;

        if(N < 0){
            N = -N;
            return 1 / ans(x,N);
        }

        double half = ans(x,N/2);
        
        if(N % 2 == 0)  return half * half;

        return x * half * half;
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        return ans(x,n);
    }
};