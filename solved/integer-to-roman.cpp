// OJ: https://leetcode.com/problems/integer-to-roman/
// Author: https://github.com/brawnerquan
// Time: O(1) because there are only 13 roman numerals you have to look through
// Space: O(1)
class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> numerals[13] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
                                            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string answer = "";
            for(int i = 0; i < 13; ++i){
                //if we can subtract this big ass fucker without going negative we good to add that numeral
                if(num - numerals[i].first >= 0){
                    num -= numerals[i].first;
                    answer += numerals[i].second;
                    //so when I gets incremented we stay at the same I bc we check if we can subtract that fucker again
                    --i;
                }
        }
        return answer;
    }
};
