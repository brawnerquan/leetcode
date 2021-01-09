// OJ: https://leetcode.com/problems/minimum-knight-moves/
// Author: https://github.com/brawnerquan
// Time: O(???)
// Space: O(a lot)
class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<int,int>> queue;
        int poss_moves[8][2] = {{1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-1,2}, {-2,1}};
        vector<vector<bool>> visited(310, vector<bool>(310, false));
        queue.push({0,0});
        pair<int,int> top;
        int answer = 0;
        int size;
        //constrain the search space to 1/4th the size
        x = abs(x);
        y = abs(y);
        //swap to reduce to 1/8th
        if(y > x){
            size = x;
            x = y;
            y = size;
        }
        if(x == 0 and y == 0)
            return 0;
        while(!queue.empty()){
            size = queue.size();
            for(int i = 0; i < size; ++i){
                top = queue.front();
                for(int j = 0; j < 8; ++j){
                    if(top.first + poss_moves[j][0] >= -2 and top.first + poss_moves[j][0] >= top.second + poss_moves[j][1] and top.second + poss_moves[j][1] >= -2){
                        if(visited[top.first + poss_moves[j][0] + 2][top.second + poss_moves[j][1] + 2] == false){
                            visited[top.first + poss_moves[j][0] + 2][top.second + poss_moves[j][1] + 2] = true;
                            //save time so we don't put extra shit on the stack once we have the answer already
                            if(top.first + poss_moves[j][0] == x and top.second + poss_moves[j][1] == y)
                                return answer + 1;
                            else
                                queue.push({top.first + poss_moves[j][0], top.second + poss_moves[j][1]});
                        }
                    }
                }
                queue.pop();
            }
            ++answer;
        }
        return answer;
    }
};
