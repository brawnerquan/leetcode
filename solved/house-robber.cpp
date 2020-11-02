// OJ: https://leetcode.com/problems/house-robber/
// Author: https://github.com/brawnerquan
// Time: O(n) just one iteration through the array is needed
// Space: O(1) just modify the array to contain the max profit that could be made of the subarray from 0 to index i
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        if(nums.size() == 3)
            return max(nums[0] + nums[2], nums[1]);
        //prepare the front of the array for our iteration through it, size at this point must be > 3 aka 4 or more
        nums[2] += nums[0];
        for(int i = 3; i < nums.size(); ++i){
            nums[i] += max(nums[i - 2], nums[i - 3]);
        }
        return max(nums[nums.size() - 1], nums[nums.size() - 2]);
    }
};
