// OJ: https://leetcode.com/problems/climbing-stairs/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};