// OJ: https://leetcode.com/problems/combination-sum/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()
//solved iteratively and recursively
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        stack<tuple<int,int,int,int>> stack;
        vector<int> curr_path;
        /*prep the stack*/
        for(int i = 0; i < candidates.size(); ++i){
            if(target - candidates[i] == 0){
                curr_path.push_back(candidates[i]);
                answer.push_back(curr_path);
                curr_path.pop_back();
                continue;
            }
            stack.push({candidates[i], target - candidates[i], i, 0});
        }

        tuple<int,int,int,int> top;

        while(!stack.empty()){
            top = stack.top();
            stack.pop();

            while(curr_path.size() > get<3>(top))
                curr_path.pop_back();

            curr_path.push_back(get<0>(top));


                for(int i = get<2>(top); i < candidates.size(); ++i){
                    if(get<1>(top) - candidates[i] == 0){
                        curr_path.push_back(candidates[i]);
                        answer.push_back(curr_path);
                        curr_path.pop_back();
                    }else if(get<1>(top) - candidates[i] > 0){
                        stack.push({candidates[i], get<1>(top) - candidates[i], i, get<3>(top) + 1});
                    }
                }
        }
        return answer;
    }

};


/*class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, answer, vector<int>(), 0, target);
        return answer;
    }
    void findCombinations(vector<int>& candidates, vector<vector<int>> &answer, vector<int> curr_path, int cand_i, int target_distance){

        //otherwise, try subtracting all candidates
        for(int i = cand_i; i < candidates.size(); ++i){
            curr_path.push_back(candidates[i]);
            //if we're zero from the target we have sucessfully found a path to it!
            if(target_distance - candidates[i] == 0){
                answer.push_back(curr_path);
                return;
            }else if(target_distance - candidates[i] < 0){//or if we've overshot our target we have to discard this path
                return;
            }else{
                findCombinations(candidates, answer, curr_path, i, target_distance - candidates[i]);

            }
            curr_path.pop_back();
        }
    }
};
*/
