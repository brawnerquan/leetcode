// OJ: https://leetcode.com/problems/plus-one/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n) bc of vector insert under the hood
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr_digit = digits.size() - 1;
        ++digits[curr_digit];
        while(digits[curr_digit] == 10){
            digits[curr_digit] = 0;
            --curr_digit;
            //watch out for negative indicies
            if(curr_digit < 0){
                digits.insert(digits.begin(), 0);
                curr_digit = 0;
            }
            ++digits[curr_digit];
        }
        return digits;
    }
};
