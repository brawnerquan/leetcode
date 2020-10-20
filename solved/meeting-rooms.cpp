// OJ: https://leetcode.com/problems/meeting-rooms/
// Author: https://github.com/brawnerquan
// Time: O(NlogN) to sort and then one N iterative pass. 
// Space: O(1) constant, in place
//NEED TO DO SOME LEARNING ON LAMBDA EXPRESSIONS. SEEMS TO BE A LITTLE FASTER USING THEM
//https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019
class Solution {
    const int END = 1;
    const int BEGIN = 0;
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& l, vector<int>& r){return l.at(0) < r.at(0);});
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i - 1][END] > intervals[i][BEGIN])
                return false;
        }
         return true;       
    }
};