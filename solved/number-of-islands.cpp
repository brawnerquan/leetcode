// OJ: https://leetcode.com/problems/number-of-islands/
// Author: https://github.com/brawnerquan
// Time: O(n * m), gotta visit every thing in the grid
// Space: O(???)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int num_islands = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    to_explore.push({i, j});
                    explore(grid);
                    ++num_islands;
                }
            }
        }
        return num_islands;
    }
    void explore(vector<vector<char>>& grid){
        pair<int,int> coords;
        while(!to_explore.empty()){
            coords = to_explore.front();
            to_explore.pop();
            if(coords.second + 1 < n and grid[coords.first][coords.second + 1] == '1'){
                grid[coords.first][coords.second + 1] = '0';
                to_explore.push({coords.first, coords.second + 1});
            }
            if(coords.second - 1 >= 0 and grid[coords.first][coords.second - 1] == '1'){
                grid[coords.first][coords.second - 1] = '0';
                to_explore.push({coords.first, coords.second - 1});
            }
            if(coords.first + 1 < m and grid[coords.first + 1][coords.second] == '1'){
                grid[coords.first + 1][coords.second] = '0';
                to_explore.push({coords.first + 1, coords.second});
            }
            if(coords.first - 1 >= 0 and grid[coords.first - 1][coords.second] == '1'){
                grid[coords.first - 1][coords.second] = '0';
                to_explore.push({coords.first - 1, coords.second});
            }
        }
    }
private:
    queue<pair<int,int>> to_explore;
    int m, n;
};
