// OJ: https://leetcode.com/problems/palindrome-partitioning/
// Author: https://github.com/brawnerquan
// Time: O(2^n)
// Space: O(2^n)


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> dp(s.length());
        vector<string> base_cases;
            base_cases.push_back(string(1, s[0]));
            dp[0].push_back(base_cases);
        for(int i = 1; i < s.length(); ++i){
            for(int j = 0; j <= i; ++j){
                if(isPalindrome(s, j, i)){
                    if(j == 0){//if j == 0, we have a palindrome from 0 to i, make a new entry
                        dp[i].push_back(vector<string>(1, s.substr(j, i - j + 1)));
                    }else{
                        for(int k = 0; k < dp[j - 1].size(); ++k){
                            vector<string> temp_vector = dp[j - 1][k];
                            temp_vector.push_back(s.substr(j, i - j + 1));
                            dp[i].push_back(temp_vector);
                        }
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
    bool isPalindrome(string &s, int j, int i){
        if(i == j)
            return true;
        if(i - j % 2 == 0){//odd sized palindrome
            while(j != i){
                if(s[j] != s[i])
                    return false;
                ++j;
                --i;
            }
        }else{//even sized palindrome
            while(j < i){
                if(s[j] != s[i])
                    return false;
                ++j;
                --i;
            }
        }
        return true;
    }
};
