// OJ: https://leetcode.com/problems/russian-doll-envelopes/
// Author: https://github.com/brawnerquan
// Time: O(nlogn) this solution is literally like 10x faster than the n^2 approach.
// sort by width and if two elements have the same width, sort by decreasing height (so largest height is first)
// this makes it so you can essentially do LIS in nlogn on the heights and not worry about the widths
// Space: O(n) store the heights of the LRDE
const int WIDTH = 0;
const int HEIGHT = 1;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort using a lambda expression to pass in a custom sort comparator that gets the biggest to the front
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &left, vector<int> &right){if(left[WIDTH] == right[WIDTH]) return left[HEIGHT] > right[HEIGHT]; else return left[0] < right[0];});
        vector<int> envelopes_table;
        vector<int>::iterator search_result;
        for(int i = 0; i < envelopes.size(); i++){
            search_result = lower_bound(envelopes_table.begin(), envelopes_table.end(), envelopes[i][HEIGHT]);
            //this height is the greatest in the list, so we can extend LRDE
            if(search_result == envelopes_table.end()){
                envelopes_table.push_back(envelopes[i][HEIGHT]);
            }else if(*search_result == envelopes[i][HEIGHT]){//cant extend LRDE with the same height + wider or equal envelope width
                continue;
            }else{//we have the place of the first height that is greater than the current envelopes height
                //we want to replace the height here because we can make an identical size LRDE with a lower height, and all following
                //envelopes MUST have a greater width, so this LRDE at this size can be extended to make a bigger one in the end
                *search_result = envelopes[i][HEIGHT];
            }//you dont need to worry about replacing a LRDE with a smaller height because width is always increasing or stays the same. if its                 the same, you just replace with lower height no problem, and if the width is greater, you know any later elements widths MUST be                   greater so you dont need to worry about width and height is lower so you just replace the height!
        }
        return envelopes_table.size();
    }
private:
//     void print_vector(vector<vector<int>> vec){
//         for(int i = 0; i < vec.size(); i++){
//             for(int j = 0; j < 2; j++){
//                 cout << vec[i][j] << ", ";
//             }
//         }
//         cout << endl;
//     }
};



// OJ: https://leetcode.com/problems/russian-doll-envelopes/
// Author: https://github.com/brawnerquan
// Time: O(n^2). nlogn solution coming soon!
// Space: O(n) to store an array to keep track of the the subarray solutions
const int WIDTH = 0;
const int HEIGHT = 1;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort using a lambda expression to pass in a custom sort comparator that gets the biggest to the front
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &left, vector<int> &right){return left[0] > right[0];});
        int num_envelopes = 0;
        vector<int> envelopes_table(envelopes.size(), 1);
        for(int i = 0; i < envelopes.size(); i++){
            //if the new envelope we're looking at has a smaller width than the last one now check the height
            for(int j = 0; j < i; j++){
                // cout << "COMPARING: " << i << " " << i - j - 1 << endl;
                //if the envelope can fit, pick the max between your current max envelopes and the one you're looking back at
                if(envelopes[i][WIDTH] < envelopes[i - j - 1][WIDTH] and envelopes[i][HEIGHT] < envelopes[i - j - 1][HEIGHT])
                    envelopes_table[i] = max(envelopes_table[i], 1 + envelopes_table[i - j - 1]);
            }
            num_envelopes = max(num_envelopes, envelopes_table[i]);
            // cout << "MAX_ENV FOR INDEX " << i << "is: " << envelopes_table[i] << endl;
        }
        return num_envelopes;
    }
private:
//     void print_vector(vector<vector<int>> vec){
//         for(int i = 0; i < vec.size(); i++){
//             for(int j = 0; j < 2; j++){
//                 cout << vec[i][j] << ", ";
//             }
//         }
//         cout << endl;
//     }
};
