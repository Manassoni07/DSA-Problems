class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int min_ops = 1e9;

        for (int r = 0; r < n; ++r) {

            int curr_ops = r;

            for (int i = 0; i < n / 2; ++i) {
                char c1 = s[(r + i) % n];
                char c2 = s[(r + n - 1 - i) % n];
                if (c1 != c2) {
                    int diff1 = (c2 - c1 + 26) % 26;
                    int diff2 = (c1 - c2 + 26) % 26;

                    curr_ops += min(diff1, diff2);
                }
            }
            min_ops = min(min_ops, curr_ops);
        }

        return min_ops;
    }
};