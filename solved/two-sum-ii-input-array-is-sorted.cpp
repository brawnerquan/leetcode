// OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
//two pointer approach bc it's sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer(2);
        unordered_map<int, int> rems;
        for(int i = 0; i < numbers.size(); ++i){
            if(rems.find(numbers[i]) != rems.end()){
                answer[0] = rems[numbers[i]] + 1;
                answer[1] = i + 1;
                return answer;
            }else{
                rems.insert({target - numbers[i], i});
            }
        }
        return answer;
    }
};
