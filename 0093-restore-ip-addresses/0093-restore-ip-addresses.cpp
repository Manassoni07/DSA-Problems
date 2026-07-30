class Solution {
private:
    void backtrack(const string& s, int index, int dots, string current, vector<string>& result) {
        // Base case: If we have placed 3 dots, check if the remaining string forms a valid segment
        if (dots == 3) {
            string segment = s.substr(index);
            if (isValid(segment)) {
                result.push_back(current + segment);
            }
            return;
        }

        // Try placing a dot after 1, 2, or 3 digits
        for (int len = 1; len <= 3 && index + len < s.length(); ++len) {
            string segment = s.substr(index, len);
            if (isValid(segment)) {
                backtrack(s, index + len, dots + 1, current + segment + ".", result);
            }
        }
    }

    bool isValid(const string& segment) {
        if (segment.empty() || segment.length() > 3) return false;
        // Check for leading zero
        if (segment.length() > 1 && segment[0] == '0') return false;
        // Check numerical value <= 255
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        // Pruning: A valid IP length is strictly between 4 and 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }

        backtrack(s, 0, 0, "", result);
        return result;
    }
};