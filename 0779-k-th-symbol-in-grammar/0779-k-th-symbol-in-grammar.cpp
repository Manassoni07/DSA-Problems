class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        // pow(2, n-1) give length of nth row
        if(k <= pow(2,n-1)/2){
            return kthGrammar(n-1,k);
        }
        return !kthGrammar(n-1,k-(pow(2,n-1)/2));
    }
};