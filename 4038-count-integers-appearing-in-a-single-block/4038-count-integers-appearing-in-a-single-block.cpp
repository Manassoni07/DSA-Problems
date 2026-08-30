class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
         bitset<101> app1=0, app2=0;
        int prv=-1;
        for(int x : nums){
            bool set1=(!app1[x] || x==prv);
            bool cnt1= set1 && (!app2[x]);
            app1[x]=cnt1;
            app2[x]=app2[x]|!set1;  
            prv=x;
        }
        return app1.count();
    }
};