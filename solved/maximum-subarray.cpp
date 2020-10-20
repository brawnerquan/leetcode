// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //since we're looking at contiguous sums, just check the element right behind the current one
        int max_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i] + nums[i - 1], nums[i]);
            if(max_sum < nums[i])
                max_sum = nums[i];
        }
        return max_sum;
    }
};