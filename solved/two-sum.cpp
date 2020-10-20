// OJ: https://leetcode.com/problems/two-sum/
// Author: https://github.com/brawnerquan
// Time: O(n) where n is the number of n
// Space: O(N)  unordered_map space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nummap;
        vector<int> answer;
        for(size_t i = 0; i < nums.size(); i++){
            int remainder = target - nums[i]; // calculate remainder
            std::unordered_map<int, int>::const_iterator index = nummap.find(remainder);//check if number is in the map
            if(index != nummap.end() and i != index->second){//if the number is in the map + the indicies are not the same
                answer.push_back(i);
                answer.push_back(index->second);
                return answer;
            }
            nummap[nums[i]] = i; //add number to map, key is number, value is index
        }
        return answer;
    }
};