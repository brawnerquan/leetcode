// OJ: https://leetcode.com/problems/minimum-cost-for-tickets/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()INCOMPLETE
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int minCost = 0;
        float num_days, pass_7, pass_30;
        vector<float> dp1(days.size(), costs[0]);
        vector<float> dp2(days.size(), 1001);
        vector<float> dp3(days.size(), 1001);
        //now go through and see if we can lower the cost for each day
        for(int i = 0; i < days.size(); ++i){
            //calculate average cost of a 7 day pass if we started one this day
            for(num_days = 0; i + num_days < days.size() and days[i + num_days] < days[i] + 7; ++num_days){
            }
            cout << "NUM DAYS THAT FIT IN RANGE I: " << i << ", " << num_days << endl;
            pass_7 = costs[1] / num_days;
            for(num_days = 0; i + num_days < days.size() and days[i + num_days] < days[i] + 7; ++num_days){
                dp2[i + num_days] = min(dp2[i + num_days], pass_7);
            }
            //calculate average cost of a 30 day pass if we started one this day
            for(num_days = 0; i + num_days < days.size() and days[i + num_days] < days[i] + 30; ++num_days){
            }
            pass_30 = costs[2] / num_days;
            cout << "PASS 30: " << pass_30 << endl;
            for(num_days = 0; i + num_days < days.size() and days[i + num_days] < days[i] + 30; ++num_days){
                dp3[i + num_days] = min(dp3[i + num_days], pass_30);
            }
        }
        print_vector(dp1);
        print_vector(dp2);
        print_vector(dp3);
        return -1;
    }
    void print_vector(vector<float> vec){
        for(int i = 0; i < vec.size(); i++){
                cout << vec[i] << ", ";
        }
        cout << endl;
    }
};
