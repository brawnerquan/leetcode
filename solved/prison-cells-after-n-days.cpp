// OJ: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> curr_cells(cells);
        unordered_map<int, vector<vector<int>>> seen_states;
        unordered_map<int, vector<vector<int>>>::const_iterator find;
        int bit, day;
        int cycle_bit = INT_MAX;
        bool found_cycle = false;
        next_day(cells, curr_cells);
        curr_cells[0] = 0;
        curr_cells[7]= 0;
        for(day = 1; day < N; ++day){
            //calculate bit rep for the current day
            bit = vector_toBit(curr_cells);
            //do something on this current day
            if(bit == cycle_bit){
                return seen_states[cycle_bit][(N - day) % seen_states[cycle_bit].size()];
            }else if(found_cycle == true){
                seen_states[cycle_bit].push_back(curr_cells);
            }else{
                find = seen_states.find(bit);
                //if we have seen it before, we must document the full cycle
                if(find != seen_states.end()){
                    seen_states[bit].push_back(curr_cells);
                    found_cycle = true;
                    cycle_bit = bit;
                }else{
                    seen_states[bit];
                }
            }
            //move to the next day
            next_day(cells, curr_cells);
        }
        return curr_cells;
    }
    void next_day(vector<int> &cells, vector<int> &curr_cells){
        cells = curr_cells;
        for(int j = 1; j < 7; ++j){
            if(cells[j - 1] == cells[j + 1])
                curr_cells[j] = 1;
            else
                curr_cells[j] = 0;
        }
    }
    int vector_toBit(vector<int> &vec){
        int bit = 0;
        for(int i = 1; i < vec.size() - 1; ++i){
            if(vec[i] == 1)
                bit += pow(2, i - 1);
        }
        return bit;
    }
};
