// OJ: https://leetcode.com/problems/paint-fence/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
//can be done in constant space but i hate this question
class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        vector<int> dp(n);
        dp[0] = k;
        dp[1] = k * (k - 1) + k;
        for(int i = 2; i < n; ++i){
            dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
        }
        return dp[n - 1];
    }
};
