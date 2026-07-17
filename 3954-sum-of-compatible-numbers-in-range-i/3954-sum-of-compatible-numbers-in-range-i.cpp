class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        long long ans = 0;

        int l = max(1, n - k);
        int r = n + k;

        for (int x = l; x <= r; x++) {
            if ((n & x) == 0) {
                ans += x;
            }
        }

        return (int)ans;
    }
};