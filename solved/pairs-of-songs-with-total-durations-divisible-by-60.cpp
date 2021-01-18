// OJ: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> songs;
        int num_pairs = 0;
        int curr;
        for(int i = 0; i < time.size(); ++i){
            curr = time[i] % 60;

            if(songs.find(curr) != songs.end())
                num_pairs += songs[curr];
            
            //catch 60 as itll get inserted as 0 and 60 if you dont do this
            curr = (60 - curr) % 60;
            if(songs.find(curr) == songs.end())
                songs[curr] = 1;
            else
                ++songs[curr];

        }
        return num_pairs;
    }
};
