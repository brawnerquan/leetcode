// OJ: https://leetcode.com/problems/minimum-cost-for-tickets/
// Author: https://github.com/brawnerquan
// Time: O(1) O(n) if the number of days was n
// Space: O(1)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int total_cost[366] = {INT_MAX};
        bool isDay[366] = {false};
        for(int i = 0; i < days.size(); ++i){
            isDay[days[i]] = true;
        }
        total_cost[0] = 0;
        int min_cost = min({costs[0], costs[1], costs[2]});
        for(int i = 1; i < 366; ++i){
            if(isDay[i] == false){
                total_cost[i] = total_cost[i - 1];
            }else{
                //by default the cost is the lowest cost ticket
                total_cost[i] = total_cost[i - 1] + min_cost;
                if(i - 7 >= 0)
                    total_cost[i] = min(total_cost[i], total_cost[i - 7] + costs[1]);
                else
                    total_cost[i] = min(total_cost[i], costs[1]);
                if(i - 30 >=0)
                    total_cost[i] = min(total_cost[i], total_cost[i - 30] + costs[2]);
                else
                    total_cost[i] = min(total_cost[i], costs[2]);
            }
        }
        return total_cost[365];
    }
};
