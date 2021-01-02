// OJ: https://leetcode.com/problems/decode-ways/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
//optimized to use constant space

class Solution {
public:
    int numDecodings(string s) {
        //base case
        if(s.length() == 1){
            if(s[0] == '0')
                return 0;
            else
                return 1;
        }
        //i - 2
        int dp_2 = 1;//since dp_2 actually exist dosen't at init, it has 1 decoding because there is 1 way to make a valid 2 digit number at start
        //i - 1
        int dp_1 = 0;
        //dp[i]
        int dp_0;
        //if the first isn't 0, there is one way to decode it!
        if(s[0] != '0')
            dp_1 = 1;
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == '0'){//if current is 0 can only make a digit if the previous is 1 or 2
                if(s[i - 1] == '1' or s[i - 1] == '2')
                    dp_0 = dp_2;//only for this to work is by building a 2 digit char rn.. if we cant, then its 0
                else
                    dp_0 = 0;
            }else if(s[i - 1] == '0' or s[i - 1] > '2' or (s[i - 1] == '2' and s[i] > '6')){//previous is 0 or >2 or the 2 digit num is >26, cant
                dp_0 = dp_1;//so can only decode using just our current digit which does not add any more ways
            }else{//otherwise we have a valid 2 digit number :D
                dp_0 = dp_2 + dp_1;
            }
            //now shift our dp variables
            dp_2 = dp_1;
            dp_1 = dp_0;

        }
        return dp_0;
    }
};

/* non constant space :(
class Solution {
public:
    int numDecodings(string s) {
        //base case
        if(s.length() == 1){
            if(s[0] == '0')
                return 0;
            else
                return 1;
        }
        vector<int> dp(s.length(), 0);
        //otherwise, setup first 2 indicies
        if(s[0] == '0'){
            dp[0] = 0;
            dp[1] = 0;
        }else if(s[1] == '0'){
            if(s[0] == '1' or s[0] == '2')//possible to make one combo!
                dp[1] = 1;
        }else{//neither are 0, no matter what dp[0] is 1
            dp[0] = 1;
            if(s[0] > '2')//if prev is greater than 2, impossible to make a char using prev
                dp[1] = 1;
            else if(s[0] == '2' and s[1] > '6')//so if prev is 2, can't be greater than 6
                dp[1] = 1;//since greater than 26 we cant
            else //prev is greater than 0, less than 3, and possible is less than 26
                dp[1] = 2;
        }
        for(int i = 2; i < s.length(); ++i){
            if(s[i] == '0'){//if current is 0 can only make a digit if the previous is 1 or 2
                if(s[i - 1] == '1' or s[i - 1] == '2')
                    dp[i] = dp[i - 2];//only for this to work is by building a 2 digit char rn.. if we cant, then its 0
            }else if(s[i - 1] == '0' or s[i - 1] > '2'){//if the previous is 0 or 3 or greater, we can't build a 2 digit char
                dp[i] = dp[i - 1];//so can only decode using just our current digit which does not add any more ways
            }else{//can make a letter using 2 digits, as long as we're not greater than 26
                if(s[i - 1] == '2' and s[i] > '6')//the 2 digit number would be greater than 26 so we can't make a 2 digit
                    dp[i] = dp[i - 1];
                else
                    dp[i] = dp[i - 2] + dp[i - 1];
            }
        }
        return dp[s.length() - 1];
    }
};

*/
