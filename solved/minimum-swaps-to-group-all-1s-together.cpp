// OJ: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int num_ones = 0;
        for(int i = 0; i < data.size(); ++i){
            if(data[i] == 1)
                ++num_ones;
        }
        int ones_window = 0;
        for(int i = 0; i < num_ones; ++i){
            ones_window += data[i];
        }
        int max_window = ones_window;
        for(int i = num_ones; i < data.size(); ++i){
            ones_window -= data[i - num_ones];
            ones_window += data[i];
            max_window = max(ones_window, max_window);
        }
        return num_ones - max_window;
    }
};
