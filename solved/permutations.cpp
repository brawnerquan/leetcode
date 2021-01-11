// OJ: https://leetcode.com/problems/permutations/
// Author: https://github.com/brawnerquan
// Time: O(n!)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        permute(answer, nums, 0);
        return answer;
    }
    void permute(vector<vector<int>> &answer, vector<int> &nums, int low){
            if(low == nums.size())
                answer.push_back(nums);
        for(int i = low; i < nums.size(); ++i){
            swap(nums, low, i);
            permute(answer, nums, low + 1);
            swap(nums, low, i);
        }
    }
    void swap(vector<int> &nums, int id1, int id2){
        int temp = nums[id1];
        nums[id1] = nums[id2];
        nums[id2] = temp;
    }
};
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        dfs(answer, nums, vector<int>(), -1);
        return answer;
    }
    void dfs(vector<vector<int>> &answer, vector<int> remaining_nums, vector<int> curr_path, int to_remove){
        //erase now so we don't have to copy a vector twice
        if(to_remove != -1)
            remaining_nums.erase(remaining_nums.begin() + to_remove);
        if(remaining_nums.size() == 0)
            answer.push_back(curr_path);
        for(int i = 0; i < remaining_nums.size(); ++i){
            curr_path.push_back(remaining_nums[i]);
            dfs(answer, remaining_nums, curr_path, i);
            curr_path.pop_back();
        }
    }
};
*/
