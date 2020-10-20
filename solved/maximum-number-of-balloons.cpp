// OJ: https://leetcode.com/problems/maximum-number-of-balloons/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
//This solution works with any target string given. A more robust solution than the commented out one but a little slower.
class Solution {
const string TARGET = "balloon";
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};
        int targ_arr[26] = {0};
        for(int i = 0; i < text.size(); i++){
            arr[text[i] - 'a']++;
        }
        for(int i = 0; i < TARGET.size(); i++){
            targ_arr[TARGET[i] - 'a']++;
        }
        bool negative_found = false;
        int min_count = 0;
        while(!negative_found){
            for(int i = 0; i < 26; i++){
                if(arr[i] - (targ_arr[i] * (min_count + 1)) < 0)
                    negative_found = true;
            }
            if(negative_found == true)
                return min_count;
            min_count++;
        }
        return min_count;
    }
};
//         string key = "ban";
//         string double_key = "lo";
//         int min_count = INT_MAX;
//         for(int i = 0; i < double_key.size(); i++){
//             if(arr[double_key[i] - 'a']/2 < min_count)
//                 min_count = arr[double_key[i] - 'a']/2;
//         }
//         for(int i = 0; i < key.size(); i++){
//             if(arr[key[i] - 'a'] < min_count)
//                 min_count = arr[key[i] - 'a'];
//         }