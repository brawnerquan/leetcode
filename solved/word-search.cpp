// OJ: https://leetcode.com/problems/word-search/
// Author: https://github.com/brawnerquan
// Time: O(N * 3^L) where L is the length of the word as you have to try starting from everywhere in the grid and N times and you have to check up
// to 3 directions
// Space: O(N) as the only space needed is space on the stack for recursion 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    if(search(board, i, j, word, 1))
                        return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, int row, int col, string &word, int counter){
        if(counter == word.length())
            return true;
        board[row][col] = '#';

        if(row - 1 >= 0 and board[row - 1][col] == word[counter] and board[row - 1][col] != '#'){
            if(search(board, row - 1, col, word, counter + 1))
                return true;
        }
        if(row + 1 < m and board[row + 1][col] == word[counter] and board[row + 1][col] != '#'){
            if(search(board, row + 1, col, word, counter + 1))
                return true;
        }
        if(col - 1 >= 0 and board[row][col - 1] == word[counter] and board[row][col - 1] != '#'){
            if(search(board, row, col - 1, word, counter + 1))
                return true;
        }
        if(col + 1 < n and board[row][col + 1] == word[counter] and board[row][col + 1] != '#'){
            if(search(board, row, col + 1, word, counter + 1))
                return true;
        }
        board[row][col] = word[counter - 1];

        return false;
    }
private:
    int m, n;
};
