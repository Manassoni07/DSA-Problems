class Solution {
public:
    long long int dp[20][2][2][20][20]; // Memoization: level, tight, carry, length of a, length of b

    long long int fun(int level, int tight, int carry, int l, int r, int m, string& s) {
        if (level == m) return carry == 0; // Base case: valid if no carry left
        if (dp[level][tight][carry][l][r] != -1) return dp[level][tight][carry][l][r];

        long long ans = 0;
        int lim = tight ? s[level] - '0' : 9; // Max digit allowed

        int s1 = (level < l) ? 1 : 0, e1 = (level < l) ? 9 : 0;
        int s2 = (level < r) ? 1 : 0, e2 = (level < r) ? 9 : 0;

        for (int a = s1; a <= e1; a++) {
            for (int b = s2; b <= e2; b++) {
                int sum = a + b + carry;
                int de = sum % 10;
                int ucarry = sum / 10;
                int utight = tight && (de == lim);
                if (de == lim) ans += fun(level + 1, utight, ucarry, l, r, m, s);
            }
        }

        return dp[level][tight][carry][l][r] = ans; // Memoize and return
    }

    long long countNoZeroPairs(long long n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int m = s.size();

        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for (int l = 1; l <= m; l++) {
            for (int r = 1; r <= m; r++) ans += fun(0, 1, 0, l, r, m, s);
        }
        return ans;
    }
};