class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        int i = 0;
        int j = height.size() - 1;

        while(i < j){
            int w = j - i;
            int h = min(height[i],height[j]);
            int area = w * h;

            maxWater = max(area,maxWater);

            if(height[i] > height[j]){
                j--; // i greedly prefer maximum height 
            }
            else{
                i++;
            }
        }
        return maxWater;
    }
};