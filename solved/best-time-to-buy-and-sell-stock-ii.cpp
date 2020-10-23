// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author: https://github.com/brawnerquan
// Time: O(n) done in one pass
// Space: O(1) only need to store the max_profit in one variable
/*
sample test case:
input           expected
[7,1,5,3,6,9]   10
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        //a list of size 1 can't make any profit so we set it to 0
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            //our max_profit for the subarray from 0 up to i is the max of the previous subarrays profit and the potential new profit by buying at the previous price and selling and the current price. if the new trade is profitable it will be the new max
            max_profit = max(max_profit, max_profit + prices[i] - prices[i - 1]);
        }
        return max_profit;
    }
};