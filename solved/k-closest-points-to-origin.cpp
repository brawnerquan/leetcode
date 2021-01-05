// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](pair<double, vector<int>> &left, pair<double, vector<int>> &right){return left.first > right.first;};
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, decltype(compare)> min_heap(compare);
        for(int i = 0; i < points.size(); ++i){
            min_heap.push({pow(points[i][0], 2) + pow(points[i][1], 2), points[i]});
        }
        vector<vector<int>> answer(K);
        for(int i = 0; i < K; ++i){
            answer[i] = min_heap.top().second;
            min_heap.pop();
        }
        return answer;
    }
};
