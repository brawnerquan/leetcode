// OJ: https://leetcode.com/problems/triangle/
// Author: https://github.com/brawnerquan
// Time: O(n^2) if n is the number of rows in the triangle
// Space: O(1) CONSTANT SPACE BABY
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j < triangle[i].size(); ++j){
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

/* solution using O(n) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //init dp array with the bottom row
        vector<int> dp(triangle[triangle.size() - 1]);
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j < triangle[i].size(); ++j){
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
*/
