class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if( n == 1 ) return s;

        long long up = n/2;
        long long down = up - 1;

        return (long long)s + (up * m) - down; 
    }
};