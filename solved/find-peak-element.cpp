// OJ: https://leetcode.com/problems/find-peak-element/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O()
//will complete the logarithmic solution another time... feeling low motivation.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 and i < nums.size() - 1){
                if(nums[i - 1] < nums[i] and nums[i] > nums[i + 1])
                    return i;
            }else if(i == 0){
                if(nums[i] > nums[i + 1])
                    return i;
            }else{
                if(nums[i] > nums[i - 1])
                    return i;
            }
        }
        return -1;
    }
};
/*
4 cases:
both L and R are less than, which means you're at a peak
LR are both greater, which means you check L - 1 or R + 1
L is greater R is less, so there is no point on checking R + 1 and you only check L - 1
L is less, R is greater, so don't check L - 1 and only check R + 1
*/
