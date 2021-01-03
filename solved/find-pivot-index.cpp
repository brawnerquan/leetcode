// OJ: https://leetcode.com/problems/find-pivot-index/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1) this question sucks but we got it i guess
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        int sum = 0;
        //done in place
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            nums[i] = sum;
        }
        if(nums[nums.size() - 1] - nums[0] == 0)
            return 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i - 1] == nums[nums.size() - 1] - nums[i])
                return i;
        }
        return -1;
    }
};




/*
REALLY SHITTY LINEAR TIME SOLUTION MY BRAIN IS SO SMALL
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        int left, right, pivot;
        left = 0;
        right = accumulate(nums.begin() + 1, nums.end(), 0);
        for(int i = 0; i < nums.size() - 1; ++i){
            if(left == right)
                return i;
            //if this pivot doesn't work, increment to the next pivot
            left += nums[i];
            right -= nums[i + 1];
        }
        if(left == right)
                return nums.size() - 1;
        return -1;
    }
};
*/
