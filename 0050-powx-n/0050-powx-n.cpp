class Solution {
    double solve(double x, long long N){
        if(N == 0) return 1;

        double half = solve(x,N/2);

        if(N % 2 == 0) return half * half;

        return x * half * half;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if(x == 1) return 1.0;
        if(N<0){
            N = -N;
            return 1 / solve(x,N);
        }
        return solve(x,N);
    }
};