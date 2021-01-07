// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int save;
        int trapped_water = 0;
        while(left < right){
            if(height[left] <= height[right]){
                save = height[left];
                while(height[++left] < save)
                    trapped_water += save - height[left];
            }else{
                save = height[right];
                while(height[--right] < save)
                    trapped_water += save - height[right];
            }
        }
        return trapped_water;
    }
};
