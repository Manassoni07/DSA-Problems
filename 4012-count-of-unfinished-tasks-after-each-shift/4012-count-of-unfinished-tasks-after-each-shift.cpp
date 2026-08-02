class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<int> res;

        vector<long long> pref(n, 0);
        pref[0] = tasks[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + tasks[i];
        }

        int idx = 0;
        long long carry = 0;

        for (long long i : shifts) {
            long long rem;
            if (idx == 0)
                rem = pref[n - 1] - carry;
            else
                rem = pref[n - 1] - pref[idx - 1] - carry;

            if (i >= rem) {
                res.push_back(0);
                idx = 0;
                carry = 0;
                continue;
            }
            while (idx < n && i > 0) {
                long long temp = tasks[idx] - carry;

                if (i >= temp) {
                    i -= temp;
                    idx++;
                    carry = 0;
                } else {
                    carry += i;
                    i = 0;
                }
            }

            if (idx == n) {
                res.push_back(0);
                idx = 0;
                carry = 0;
            } else
                res.push_back(n - idx);
        }
        return res;
    }
};