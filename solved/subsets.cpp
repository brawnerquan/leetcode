// OJ: https://leetcode.com/problems/subsets/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = pow(2, nums.size());
        vector<vector<int>> answer(size);
        for(int i = 0; i < size; ++i){
            bitset<10> bits(i);
            vector<int> curr_subset;
            for(int j = 0; j < nums.size(); ++j){
                if(bits[j] == 1)
                    curr_subset.push_back(nums[j]);
            }
            answer[i] = curr_subset;
        }
        return answer;
    }
};
