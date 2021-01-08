// OJ: https://leetcode.com/problems/course-schedule/
// Author: https://github.com/brawnerquan
// Time: O(n + m)
// Space: O(n + m)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> exploring(numCourses, false);
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); ++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//to get to this class you have to take the prereq
        }
        for(int i = 0; i < prerequisites.size(); ++i){
            if(visited[prerequisites[i][1]] == false){
                if(!topSort(prerequisites, graph, exploring, visited, prerequisites[i][1]))
                    return false;
            }
        }
        return true;
    }
    bool topSort(vector<vector<int>>& prerequisites, unordered_map<int,vector<int>> &graph, vector<bool> &exploring, vector<bool> &visited, int curr_node){
        visited[curr_node] = true;
        exploring[curr_node] = true;
        for(int i = 0; i < graph[curr_node].size(); ++i){
            if(exploring[graph[curr_node][i]] == true)
                return false;
            if(visited[graph[curr_node][i]] == false){
                if(!topSort(prerequisites, graph, exploring, visited, graph[curr_node][i]))
                    return false;
            }
        }
        exploring[curr_node] = false;
        return true;
    }
};
