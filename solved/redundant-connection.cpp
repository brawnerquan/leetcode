// OJ: https://leetcode.com/problems/redundant-connection/
// Author: https://github.com/brawnerquan
// Time: O(nlogn) because each time we look at a new edge that can be added, the most work we have to do is logn reassignment of the smaller list of representatives
// Space: O(n)
//cleaner implementation recoded... it appears the advantages of fully implementing union find aren't evident as shitty union find beats the runtime of this
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        next_id = 0;
        for(int i = 0; i < edges.size(); ++i){
            if(find(edges[i][0]) == find(edges[i][1]))
                return edges[i];
            else
                union_nodes(edges[i][0], edges[i][1]);
        }
        return vector<int>();
    }
    int find(int node){
        //if this node doesn't have an id
        if(node_map.find(node) == node_map.end()){
            node_map[node] = next_id;
            //now make it a rep and add itself to the vector
            reps[next_id].push_back(node);
            ++next_id;
        }
        return node_map[node];
    }
    void union_nodes(int left, int right){
        //get reps
        int left_rep = find(left);
        int right_rep = find(right);
        //if we need to merge left to right as right is bigger, swap L and R so we can always merge right to left
        if(reps[left_rep].size() < reps[right_rep].size()){
            int temp = left;
            left = right;
            right = left;
            temp = left_rep;
            left_rep = right_rep;
            right_rep = temp;
        }
        //now merge right to left
        for(int i = 0; i < reps[right_rep].size(); ++i){
            //update the rep of the node
            node_map[reps[right_rep][i]] = left_rep;
            //now add it to the left node list
            reps[left_rep].push_back(reps[right_rep][i]);
        }
        //now erase the right
        reps.erase(right_rep);
    }
private:
    int next_id;
    //for a component id, starting at 0, contains all of the nodes it represents
    unordered_map<int, vector<int>> reps;
    //map to map nodes to component ids
    unordered_map<int, int> node_map;
};
/*

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
*/
