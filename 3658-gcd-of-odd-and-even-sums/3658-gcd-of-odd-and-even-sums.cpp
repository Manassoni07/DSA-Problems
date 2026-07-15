class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        //even sum = n(n + 1)
        int evenSum = n * (n + 1);
        int oddSum = n * n;

        return gcd(evenSum,oddSum);
    }
};