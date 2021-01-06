// OJ: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int answer = 0;
        int abc[3];
        for(int i = 0; i < s.length() - 2; ++i){
            //reset frequency counter
            abc[0] = 0;
            abc[1] = 0;
            abc[2] = 0;
            for(int j = i; j < s.length(); ++j){
                ++abc[s[j] - 'a'];
                if(abc[0] > 0 and abc[1] > 0 and abc[2] > 0){
                    while(abc[0] > 0 and abc[1] > 0 and abc[2] > 0){
                        answer += s.length() - j;
                        --abc[s[i] - 'a'];
                        ++i;
                    }
                }
            }
        }
        return answer;
    }
};
