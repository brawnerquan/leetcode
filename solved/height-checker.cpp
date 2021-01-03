// OJ: https://leetcode.com/problems/height-checker/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()

/* STUPID SOLUTION USING SORTING... trying to figure out the O(N) algorithm
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int answer = 0;
        vector<int> sorted_heights(heights);
        sort(sorted_heights.begin(), sorted_heights.end());
        for(int i = 0; i < heights.size(); ++i){
            if(heights[i] != sorted_heights[i])
                ++answer;
        }
        return answer;
    }
};
*/
