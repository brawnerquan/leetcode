// OJ: https://leetcode.com/problems/find-the-town-judge/
// Author: https://github.com/brawnerquan
// Time: O(E)
// Space: O(N)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size() < N - 1)
            return -1;
        if(trust.size() == 0)
            return 1;
        vector<int> people(N + 1, 0);
        for(int i = 0; i < trust.size(); ++i){
            //if someone trusts another person, decrease their count because they can't be the judge
            --people[trust[i][0]];
            //increment the indegrees of the recepient- judge should be incremented N-1 times and decremented 0 times
            ++people[trust[i][1]];
        }
        for(int i = 0; i < people.size(); ++i){
            if(people[i] == N - 1)
                return i;
        }
        return -1;
    }
};
