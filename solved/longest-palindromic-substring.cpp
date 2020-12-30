// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: https://github.com/brawnerquan
// Time: O(n^2)
// Space: O(1) for centering around all possible palindromes, O(n^2) for DP

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        int longest_length = 0;
        string temp;
        for(int i = 0; i < s.length(); ++i){
            temp = longestPalindrome(s, i, i);
            if(temp.length() > longest_length){
                longest = temp;
                longest_length = temp.length();
            }
            if(i + 1 < s.length() and s[i] == s[i + 1])
                temp = longestPalindrome(s, i, i + 1);
            if(temp.length() > longest_length){
                longest = temp;
                longest_length = temp.length();
            }
        }
        return longest;
    }

    string longestPalindrome(string &s, int low, int high){
        while(low - 1 >= 0 and high + 1 < s.length() and s[low - 1] == s[high + 1]){
            --low;
            ++high;
        }
        return s.substr(low, high - low + 1);
    }

};
/*dp Solution

*/
