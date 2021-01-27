// OJ: https://leetcode.com/problems/3sum/
// Author: https://github.com/brawnerquan
// Time: O(nlogn) to sort
// Space: O(n) to store all possible answers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = INT_MAX;
        int low, high, curr_sum, target;
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0)
                return answer;
            if(nums[i] == prev)
                continue;
            else
                prev = nums[i];
            target = -nums[i];
            low = i + 1;
            high = nums.size() - 1;
            while(low < high and low >= 0 and high < nums.size()){
                //with the current nums[i] as the first element, we cannot remake a 3sum with any 2nd element that we have already seen
                curr_sum = nums[low] + nums[high];
                if(curr_sum < target){
                    ++low;
                }else if(curr_sum > target){
                    --high;
                }else{//if we have the target and the second element has never been used to make a sum with the current first element, count it
                    answer.push_back({nums[i], nums[low], nums[high]});
                    //increment low until we find a new second element
                    while(++low < nums.size() and nums[low - 1] == nums[low]);
                }
            }
        }
        return answer;
    }
};
