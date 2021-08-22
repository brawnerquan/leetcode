// OJ: https://leetcode.com/problems/spiral-matrix/
// Author: https://github.com/brawnerquan
// Time: O(n * m)
// Space: O(n * m)
class Solution {
    const int NORTH = 0;
    const int EAST = 1;
    const int SOUTH = 2;
    const int WEST = 3;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0;
        int y = 0;
        //start going east
        int dir = 1;
        vector<int> answer;
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(true){
            answer.push_back(matrix[x][y]);
            matrix[x][y] = INT_MAX;//mark visited

            //check if you can keep moving in the correct direction
            if(x + dirs[dir][0] >= 0 and x + dirs[dir][0] < matrix.size() and y + dirs[dir][1] >= 0 and y + dirs[dir][1] < matrix[0].size() and matrix[x + dirs[dir][0]][y + dirs[dir][1]] != INT_MAX){
               //we can move here so we move and go on
                x += dirs[dir][0];
                y += dirs[dir][1];

            }else{//otherwise, we turn directions
                ++dir;
                dir = dir % 4;
                if(x + dirs[dir][0] >= 0 and x + dirs[dir][0] < matrix.size() and y + dirs[dir][1] >= 0 and y + dirs[dir][1] < matrix[0].size() and matrix[x + dirs[dir][0]][y + dirs[dir][1]] != INT_MAX){
                    //we can move here so we move and go on
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                }else{
                    break;
                }

            }
        }



        return answer;
    }
};
