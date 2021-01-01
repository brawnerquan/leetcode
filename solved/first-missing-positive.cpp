// OJ: https://leetcode.com/problems/first-missing-positive/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1) //constant space is slower than using the map so depends on what you want
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //clean all negatives and mark index 0 as negative if we see a 1
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= 0)
                nums[i] = 1;
            else if(nums[i] == 1 and nums[0] > -1)
                nums[0] *= -1;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1 or nums[i] == -1)
                continue;
            //if we've got a vaid number that could be part of an increasing sequence
            if(abs(nums[i]) - 1 < nums.size() and nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        int answer = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0)
                ++answer;
            else
                break;
        }
        return answer;
    }
};
/* linear time with linear space needed, still 0 ms LOL
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int lowest = 1;
        unordered_set<int> nums_seen;
        for(int i = 0; i < nums.size(); ++i){
            nums_seen.insert(nums[i]);
            if(nums[i] == lowest){
                while(nums_seen.find(lowest) != nums_seen.end())
                    ++lowest;
            }
        }
        return lowest;
    }
};
*/
