class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        vector<int> pref(n + 1, 0);
        for(int i = 0 ; i < n ; i++) {
            pref[i] = a[i];
            if(i > 0) pref[i] += pref[i - 1];
        }
        auto getSum = [&](int l, int r) {
            if(l > r) return 0;
            return l == 0 ? pref[r] : pref[r] - pref[l - 1];
        };
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n; i++) {
                int j = i + len - 1;
                if(j >= n) continue;
                for(int k = i; k < j; k++) {
                    int left = getSum(i, k);
                    int right = getSum(k + 1, j);
                    if(left < right) {
                        dp[i][j] = max(dp[i][j] , left + dp[i][k]);
                    } else if(right < left) {
                        dp[i][j] = max(dp[i][j] , right + dp[k + 1][j]);
                    } else {
                        dp[i][j] = max({dp[i][j] , right + dp[i][k], left + dp[k + 1][j]});
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};