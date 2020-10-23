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