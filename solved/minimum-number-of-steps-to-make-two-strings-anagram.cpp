// OJ: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int minSteps(string s, string t) {
        int t_count[26] = {0};
        int s_count[26] = {0};
        for(int i = 0; i < s.length(); ++i){\
            ++s_count[s[i] - 'a'];
            ++t_count[t[i] - 'a'];
        }
        int total_count = 0;
        for(int i = 0; i < 26; ++i){
            total_count += abs(t_count[i] - s_count[i]);
        }
        return total_count / 2;
    }
};
