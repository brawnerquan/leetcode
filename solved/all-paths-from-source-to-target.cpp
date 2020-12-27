// OJ: https://leetcode.com/problems/all-paths-from-source-to-target/
// Author: https://github.com/brawnerquan
// Time: O(2^n * n) as there are 2^n possible paths in the dag and the max length of one can be upper bounded by n
// Space: O(2^n * n) bc we could have to store up to that many paths
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stack<pair<int, int>> stack;
        vector<vector<int>> answer;

        int path_depth = 0;
        int target = graph.size() - 1;
        int size;
        pair<int, int> curr_node;
        vector<int> curr_path;
        stack.push({0, 0});
        while(!stack.empty()){
            curr_node = stack.top();
            stack.pop();
            //reset curr_node to be the proper depth
            while(path_depth > curr_node.second){
                --path_depth;
                curr_path.pop_back();
            }
            //add current node to the current path
            curr_path.push_back(curr_node.first);
            //now if we're at the target we good
            if(curr_node.first == target)
                answer.push_back(curr_path);

            ++path_depth;
            size = graph[curr_node.first].size();
            for(int i = 0; i < size; ++i){
                stack.push({graph[curr_node.first][i], path_depth});

            }
        }
        return answer;
    }

};

/*shitty recursive solution that wastes a lot of memory
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        findPaths(graph, vector<int>(), 0, graph.size() - 1);
        return answer;
    }
    void findPaths(vector<vector<int>> &graph, vector<int> curr_path, int curr_node, int target){
        curr_path.push_back(curr_node);
        if(curr_node == target){
            answer.push_back(curr_path);
            return;
        }
        int num_edges = graph[curr_node].size();
        for(int i = 0; i < num_edges; ++i){
            findPaths(graph, curr_path, graph[curr_node][i], target);
        }
    }
private:
    vector<vector<int>> answer;
};
*/
