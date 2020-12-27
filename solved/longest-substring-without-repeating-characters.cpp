// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1) (or technically m where m is the size of valid characters)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1);
        int curr_length = 0;
        int max_length = 0;
        int sub_front = 0;
        for(int i = 0; i < s.length(); ++i){
            //if we have seen the char before,
            if(last_seen[s[i]] != -1){
                //save the current max_length
                max_length = max(max_length, curr_length);
                //now we let the algorithm have fun and try to expand the LSS
                sub_front = max(sub_front, last_seen[s[i]]);
                curr_length = i - sub_front;
                //now update last_seen
                last_seen[s[i]] = i;
            }else{//otherwise we haven't, so we increment and mark the locaiton of when we've last seen it
                ++curr_length;
                last_seen[s[i]] = i;
            }
        }
        //finally, update max_length one more time!
        return max(max_length, curr_length);
    }
};
