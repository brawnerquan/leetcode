// OJ: https://leetcode.com/problems/gas-station/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int surplus = 0;
        int defecit = 0;
        int start_index = 0;
        for(int i = 0; i < gas.size(); ++i){
            if(surplus + gas[i] - cost[i] >= 0){
                surplus += gas[i] - cost[i];
            }else{
                defecit += gas[i] - cost[i] + surplus;
                surplus = 0;
                start_index = i + 1;
            }
        }
        if(surplus + defecit < 0)
            return -1;
        return start_index;
    }
};
