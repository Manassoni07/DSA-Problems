// recursive solution 
// tc = O(n) sc = O(n)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        solve(s, i, j);
    }
    void solve(vector<char>& s, int i, int j){
        if(i >= j) return;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        solve(s, ++i, --j);
    }
};
