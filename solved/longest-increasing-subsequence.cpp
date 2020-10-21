// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: https://github.com/brawnerquan
// Time: O(n^2) can be improved to nlogn, but still working on learning how to the nlogn implementation works. will attempt to complete asap
// Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        int lis[nums.size()];
        int lis_length = 1;
        for(int i = 0; i < nums.size(); i++){
            lis[i] = 1;
            for(int j = i; j >= 0; j--){
                //if a number behind this one is less than the current, we check if it has a better LIS than what we have stored
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){//if option we have found is better
                        lis[i] = lis[j] + 1;//make it our new LIS
                        if(lis[i] > lis_length)//store the max LIS
                            lis_length = lis[i];
                    }
                }
            }
        }
        return lis_length;
    }
};