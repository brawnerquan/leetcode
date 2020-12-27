// OJ: https://leetcode.com/problems/two-city-scheduling/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //sort by calculating a cost for each city 
        sort(costs.begin(), costs.end(), [](vector<int> &left, vector<int> &right){return left[0] - left[1] < right[0] - right[1];});
        int size = costs.size();
        int sum = 0;
        for(int i = 0; i < size / 2; ++i){
            sum += costs[i][0] + costs[i + size / 2][1];
        }
        return sum;
    }
};



/* original solution I came up with... not exactly sure if it's 100% correct
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> &left, vector<int> &right){return abs(left[0] - left[1]) > abs(right[0] - right[1]);});
        int size = costs.size();
        int a_count = 0;
        int b_count = 0;
        int sum = 0;
        for(int i = 0; i < size; ++i){
            if(costs[i][0] > costs[i][1] and b_count < size / 2 or a_count >= size / 2){
                ++b_count;
                sum += costs[i][1];
            }else{
                    ++a_count;
                    sum += costs[i][0];
            }
        }
        return sum;
    }
};

*/
