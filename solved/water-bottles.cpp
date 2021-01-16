// OJ: https://leetcode.com/problems/water-bottles/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;
        int empty = 0;
        int totalBottles;
        while(numBottles > 0){
            total += numBottles;
            totalBottles = numBottles + empty;
            numBottles = totalBottles / numExchange;
            empty = totalBottles % numExchange;
        }
        return total;
    }
};
