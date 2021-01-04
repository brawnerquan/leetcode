// OJ: https://leetcode.com/problems/coin-change/
// Author: https://github.com/brawnerquan
// Time: O(n * c) where n is the target amount and c is the number of coins
// Space: O(n)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount, INT_MAX);
        for(int i = 0; i < coins.size(); ++i){
            if(coins[i] <= amount)
                dp[coins[i] - 1] = 1;
        }
        for(int i = 0; i < amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(i - coins[j] >= 0 and dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);//find the min coin cost to get here
            }
        }
        if(dp[amount - 1] == INT_MAX)
            return -1;
        return dp[amount - 1];
    }
};
