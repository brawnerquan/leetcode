// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: https://github.com/brawnerquan
// Time: O(V + E)
// Space: O(V + E)
// kinda slow, will consider rewriting using kahn's algorithm sometime
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> req_classes;
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        stack<int> stack;
        vector<int> answer;
        for(int i = 0; i < prerequisites.size(); ++i){
            req_classes.insert(prerequisites[i][0]);
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == false){
                if(!topSort(prerequisites, stack, graph, visited, visiting, i))
                    return vector<int>();
            }
        }
        while(!stack.empty()){
            answer.push_back(stack.top());
            stack.pop();
        }
        return answer;
    }
    bool topSort(vector<vector<int>>& prerequisites, stack<int> &stack, unordered_map<int, vector<int>> &graph,
                                                                                                            vector<bool> &visited, vector<bool> &visiting, int curr_node){
        if(visiting[curr_node] == true)
            return false;
        visiting[curr_node] = true;
        for(int i = 0; i < graph[curr_node].size(); ++i){
            if(visited[graph[curr_node][i]] == false){
                if(!topSort(prerequisites, stack, graph, visited, visiting, graph[curr_node][i]))
                    return false;
            }
        }
        //no longer visiting, now we have completed visiting, thus, we have visited.
        visiting[curr_node] = false;
        visited[curr_node] = true;
        stack.push(curr_node);
        return true;
    }
};
