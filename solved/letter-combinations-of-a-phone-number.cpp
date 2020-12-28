// OJ: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: https://github.com/brawnerquan
// Time: O(4^d) where d is the number of digits
// Space: O(4^d) cos you have to store and build up all of the combinations
// Solved it iteratively and recursively!!
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answer;
        if(digits == "")
            return answer;
        queue<string> queue;
        int curr_digit;
        string front;
        queue.push("");
        while(!queue.empty()){
            front = queue.front();
            queue.pop();
            curr_digit = front.length();
            if(curr_digit == digits.length()){
                answer.push_back(front);
                continue;
            }
            for(int i = 0; i < dict[digits[curr_digit] - '2'].length(); ++i){
                queue.push(front + dict[digits[curr_digit] - '2'][i]);
            }
        }
        return answer;
    }
};
/*recursive solution
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answer;
        if(digits == "")
            return answer;
        findCombinations(answer, dict, digits, "", 0);
        return answer;
    }
    void findCombinations(vector<string> &answer, string (&dict)[8], string &digits, string curr_combo, int curr_digit){
        if(curr_digit == digits.length()){
            answer.push_back(curr_combo);
            return;
        }
        for(int i = 0; i < dict[digits[curr_digit] - '2'].length(); ++i){
                findCombinations(answer, dict, digits, curr_combo + dict[digits[curr_digit] - '2'][i], curr_digit + 1);
        }
    }
};
*/
