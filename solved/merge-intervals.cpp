// OJ: https://leetcode.com/problems/merge-intervals/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(depends on how sorting is implemented)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &left, vector<int> &right){return left[0] < right[0];});
        int size = intervals.size();
        pair<int,int> curr_range;
        curr_range.first = intervals[0][0];
        curr_range.second = intervals[0][1];
        vector<vector<int>> answer;
        for(int i = 1; i < size; ++i){
            //if the range can be expanded, expand
            if(curr_range.second >= intervals[i][0]){
                 curr_range.second = max(curr_range.second, intervals[i][1]);
            }else{//if not, add the range to the answer list and set the new range to be current range
                answer.push_back(vector<int>({curr_range.first, curr_range.second}));
                curr_range.first = intervals[i][0];
                curr_range.second = intervals[i][1];
            }
        }
        //now add the final range to the range
        answer.push_back(vector<int>({curr_range.first, curr_range.second}));
        return answer;
    }
};
