// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int curr_min_buy = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); i++){
            //if the price is below our curr min buy, update
            curr_min_buy = min(prices[i], curr_min_buy);
            //calculate and store the max profit we could make from the lowest buy price before this and selling now
            max_profit = max(prices[i] - curr_min_buy, max_profit);
        }
        return max_profit;
    }
};