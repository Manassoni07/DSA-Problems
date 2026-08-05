class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (t.size() != n) return false;

        vector<int> v(26, 0);

        for (int i = 0; i < n; i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (v[i] != 0) return false;
        }
        return true;
    }
};