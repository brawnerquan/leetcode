// OJ: https://leetcode.com/problems/longest-common-prefix/
// Author: https://github.com/brawnerquan
// Time: O(S) (length of all strings together since we need to read through every single char)
// Space: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string pref = strs[0];
        int corr_pref = 0;
        for (int i = 1; i < strs.size(); i++) {
            corr_pref = 0;
            for (int j = 0; j < min(strs[i].size(), pref.size()); j++) {
                if (strs[i][j] == pref[j])
                    corr_pref++;
                else
                    break;
            }
            if(pref.size() == 0)
                return "";
            //now resize the prefix to be only up to as far as our horizontal scan got
            pref = pref.erase(corr_pref, string::npos);
        }
        return pref;
    }
};