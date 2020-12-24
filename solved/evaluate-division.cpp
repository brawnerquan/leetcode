// OJ: https://leetcode.com/problems/evaluate-division/
// Author: https://github.com/brawnerquan
// Time: O(N * M) where N is the number of input equations and M is the number of queries
// Space: O(N) for the graph
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = equations.size();
        unordered_map<string,vector<pair<string, double>>> graph;
        //setup our graph
        for(int i = 0; i < size; ++i){
            //first go a to b
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            //then b to a
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        size = queries.size();
        vector<double> answers;
        for(int i = 0; i < size; ++i){
            unordered_set<string> visited;
            answers.push_back(traverse(graph, visited, queries[i][0], queries[i][1]));
        }
        return answers;
    }
    double traverse(unordered_map<string,vector<pair<string, double>>>& graph, unordered_set<string>& visited, string source, string target){
        visited.clear();
        stack<pair<string, double>> stk;
        pair<string, double> top;
        double cumulative_cost;
        unordered_set<string>::const_iterator find;
        int size;
        //make sure the original query exists in the graph cos if not we cant find it bro
        if(graph.find(source) == graph.end())
            return -1.0;
        stk.push({source, 1});
        while(!stk.empty()){
            top = stk.top();
            stk.pop();
            //stack stores the next node to explore and the cost it took to get there (aka the answer so far)
            cumulative_cost = top.second;
            //if the top is our target, we return the cumulative cost it's taken to get there!
            if(top.first == target)
                return cumulative_cost;
            //if we're not at our target we have to add all non_explored verticies to the queue, so get the adjacency list
            size = graph[top.first].size();
            for(int i = 0; i < size; ++i){
                find = visited.find(graph[top.first][i].first);
                //if we find the next node to be visited in the set, we already have visited it, so we don't have to look at it again
                if(find != visited.end())
                    continue;
                //otherwise, mark we're gonna visit and add it to the stack with the cost
                visited.insert(graph[top.first][i].first);
                stk.push({graph[top.first][i].first, cumulative_cost * graph[top.first][i].second});
            }
        }
