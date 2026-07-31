class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int candies = n;

        while(i < n){
            if(i < n && ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // now we start in upwards diration 
            int peak = 0;

            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                candies += peak;
                i++;
            }

            // now we move in downwards diration 
            int dip = 0;
            while(i < n && ratings[i] < ratings[i - 1]){
                dip++; 
                candies += dip;
                i++;
            }

            candies -= min(dip,peak);

        }
            return candies;
    }
};