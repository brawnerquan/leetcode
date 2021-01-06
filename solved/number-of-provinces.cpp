// OJ: https://leetcode.com/problems/number-of-provinces/
// Author: https://github.com/brawnerquan
// Time: O(n^2*logn)
// Space: O(n) only need stuff for each node
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 1)
            return 1;
        next_id = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            for(int j = i + 1; j < isConnected.size(); ++j){
                if(find(i) != find(j) and isConnected[i][j] == 1)
                    union_nodes(i, j);
            }
        }
        return reps.size();
    }
    //returns the node's rep, if no rep, creates a rep for it
    int find(int node){
        unordered_map<int,int>::const_iterator find;
        //if we do find it, return the rep
        if((find = id_map.find(node)) != id_map.end()){
            return find->second;
        }else{//otherwise, give it a rep id and then return the rep
            id_map[node] = next_id;
            reps[next_id].push_back(node);
            ++next_id;
        }
        return next_id - 1;
    }
    void union_nodes(int left, int right){
        int old_rep;
        //figure out which is bigger, then merge the smaller one to it
        if(reps[id_map[right]].size() > reps[id_map[left]].size()){//if right is bigger than left, swap the variables
            old_rep = left;
            left = right;
            right = old_rep;
        }
        //store the original rep of right so we can access it while modifying it and delete it later
        old_rep = id_map[right];
        //now we can just assume we're always merging right to left as right is smaller
        for(int i = 0; i < reps[old_rep].size(); ++i){
            id_map[reps[old_rep][i]] = id_map[left];
            reps[id_map[left]].push_back(reps[old_rep][i]);
        }
        reps.erase(old_rep);
    }
private:
    int next_id;
    unordered_map<int,int> id_map;
    unordered_map<int, vector<int>> reps;
};
