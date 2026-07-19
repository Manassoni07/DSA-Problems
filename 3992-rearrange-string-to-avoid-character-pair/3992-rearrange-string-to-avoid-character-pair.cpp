class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string cy = "";
        string cx = "";
        string rem = "";

        for(char c : s){
            if(c == x) cx += c;
            else if(c == y) cy += c;
            else rem += c;
        }

        return cy + cx + rem;
    }
};