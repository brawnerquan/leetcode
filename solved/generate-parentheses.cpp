// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: https://github.com/brawnerquan
// Time: O(fucking crazy exponential)
// Space: O(same)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        buildParens("", 0, 0, n);
        return answers;
    }
    void buildParens(string curr, int num_open, int num_close, int max){
        if(curr.length() == max * 2){
            answers.push_back(curr);
            return;
        }
        //if we haven't hit the max number of opening parenthesis
        if(num_open < max)
            buildParens(curr + "(", num_open + 1, num_close, max);
        //then, with the same curr, if we can close one parenthesis we will and recurse!
        if(num_open > num_close)
            buildParens(curr +  ")", num_open, num_close + 1, max);
    }
    private:
    vector<string> answers;
};
