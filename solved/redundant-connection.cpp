// OJ: https://leetcode.com/problems/redundant-connection/
// Author: https://github.com/brawnerquan
// Time: O(nlogn) because each time we look at a new edge that can be added, the most work we have to do is logn reassignment of the smaller list of representatives
// Space: O(n)
// for whatever even though I implemented union find it's slow af but i spent way too much time coding this lol
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> reps(edges.size());
        //1 is the rep of itself, 2 reps itself, etc... continue
        iota(reps.begin(), reps.end(), 0);
        //every rep originally only reps itself so it is of size 1
        vector<int> rep_size(edges.size(), 1);
        //stores the size and nodes of the graph that are in this rep's component
        unordered_map<int, vector<int>> rep_data;
        int original_rep;
        for(int i = 0; i < edges.size(); ++i){
            //if they have the same representative, we return this edge as the redundant edge as they're already in the same component
            if(reps[edges[i][0] - 1] == reps[edges[i][1] - 1]){
                return edges[i];
            }else{//we have to merge these components, assigning all the reps of the smaller one to the bigger one's rep
                if(rep_size[reps[edges[i][0] - 1]] < rep_size[reps[edges[i][1] - 1]]){//merge all left to right's rep
                    original_rep = reps[edges[i][0] - 1];
                    for(int j = 0; j < rep_data[original_rep].size(); ++j){
                        rep_data[reps[edges[i][1] - 1]].push_back(rep_data[original_rep][j]);
                        reps[rep_data[original_rep][j]] = reps[edges[i][1] - 1];
                        ++rep_size[reps[edges[i][1] - 1]];//increment the rep size of the right's rep
                    }
                    //erase left after all of the data is merged
                    rep_data.erase(original_rep);
                    //now change the rep of the left
                    rep_data[reps[edges[i][1] - 1]].push_back(original_rep);//add rep of the left to right's list
                    reps[original_rep] = reps[edges[i][1] - 1]; //right's rep is now the rep of left
                    ++rep_size[reps[edges[i][1] - 1]];//increment the rep size of the rights's rep
                }else{//merge all of the right to the left's rep
                    original_rep = reps[edges[i][1] - 1];
                    for(int j = 0; j < rep_data[original_rep].size(); ++j){
                        rep_data[reps[edges[i][0] - 1]].push_back(rep_data[original_rep][j]);
                        reps[rep_data[original_rep][j]] = reps[edges[i][0] - 1];
                        ++rep_size[reps[edges[i][0] - 1]];//increment the rep size of the left's rep
                    }
                    //erase right after all of the data is merged
                    rep_data.erase(original_rep);
                    //now change the rep of right
                    rep_data[reps[edges[i][0] - 1]].push_back(original_rep);//add rep of the right to left's list
                    reps[original_rep] = reps[edges[i][0] - 1]; //left's rep is now the rep of right
                    ++rep_size[reps[edges[i][0] - 1]];//increment the rep size of the left's rep
                }
            }
        }
        return vector<int>();
    }
};
