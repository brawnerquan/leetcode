// OJ: https://leetcode.com/problems/robot-bounded-in-circle/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    const int NORTH = 0;
    const int EAST = 1;
    const int SOUTH = 2;
    const int WEST = 3;
    bool isRobotBounded(string instructions) {
        int curr_dir = 0;
        pair<int,int> curr_pos = {0,0};
        for(int i = 0; i < instructions.length(); ++i){
             if(instructions[i] == 'G'){
                 if(curr_dir == NORTH)
                     curr_pos.second += 1;
                 else if(curr_dir == EAST)
                     curr_pos.first += 1;
                 else if(curr_dir == SOUTH)
                     curr_pos.second -= 1;
                 else
                     curr_pos.first -= 1;
             }else if(instructions[i] == 'R'){
                 if(curr_dir + 1 == 4)
                     curr_dir = NORTH;
                 else
                    curr_dir = curr_dir + 1;
             }else{
                 if(curr_dir - 1 == -1)
                     curr_dir = WEST;
                 else
                    curr_dir = curr_dir - 1;
             }
        }
        if(curr_dir == NORTH and !(curr_pos.first == 0 and curr_pos.second == 0))
            return false;
        return true;
    }
};
//{North = 0, East = 1, South = 2, West = 3};
