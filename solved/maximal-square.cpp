// OJ: https://leetcode.com/problems/maximal-square/
// Author: https://github.com/brawnerquan
// Time: O(m * n)
// Space: O(m * n)
//can be improved to one row needed by storing the [i - 1][j - 1] in a temp variable so you can do min of the 3 + 1 without needing more space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int answer = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '1'){
                    if(i == 0 or j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    answer = max(answer, dp[i][j]);
                }
            }
        }
        return answer * answer;
    }

};
/* non dp soltion
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int answer = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == '1')
                    answer = max(answer, findMaxSquare(matrix, i, j));
            }
        }
        return answer * answer;
    }
    int findMaxSquare(vector<vector<char>>& matrix, int i, int j){
        int curr_size = 1;
        //now attempt to expand the square size
        while(true){
            for(int k = 0; k < curr_size + 1; ++k){
                if(i + curr_size >= matrix.size() or j + curr_size >= matrix[0].size())
                    return curr_size;
                if(matrix[i + curr_size][j + k] == '0' or matrix[i + k][j + curr_size] == '0')
                    return curr_size;
            }
            ++curr_size;
        }
        return curr_size;
    }
};
*/
