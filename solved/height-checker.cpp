// OJ: https://leetcode.com/problems/height-checker/
// Author: https://github.com/brawnerquan
// Time: O(n) BRUH O(N) ACHIEVED BC OF THE STUPID ASS BOUNDS ON THE ALGORITHM
// Space: O(1)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int answer = 0;
        //use bucket sort to sort
        int buckets[100] = {0};
        for(int i = 0; i < heights.size(); ++i){
            ++buckets[heights[i] - 1];
        }
        vector<int> sorted_heights(heights.size());
        for(int i = 0; i < 100; ++i){
            while(buckets[i] != 0){
                --buckets[i];
                sorted_heights[answer] = i + 1;
                ++answer;
            }
        }
        answer = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(heights[i] != sorted_heights[i])
                ++answer;
        }
        return answer;
    }
};


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
