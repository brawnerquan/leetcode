// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min_1 = INT_MAX;
        int min_2 = INT_MAX;
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        int max_3 = INT_MIN;
        
        //now track the top 3 and the bottom two
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max_1){//new max, move max down and discard the 3rd
                max_3 = max_2;
                max_2 = max_1;
                max_1 = nums[i];
            }else if(nums[i] > max_2){//new 2nd max, move max down and discard the 3rd
                max_3 = max_2;
                max_2 = nums[i];
            }else if(nums[i] > max_3){
                max_3 = nums[i];
            }
            
            if(nums[i] < min_1){
                min_2 = min_1;
                min_1 = nums[i];
            }else if(nums[i] < min_2){
                min_2 = nums[i];
            }
        }
        
        return max(min_1 * min_2 * max_1, max_1 * max_2 * max_3);
    }
};
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         return max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3], nums[nums.size() - 1] * nums[0] * nums[1]);
    
//     }
// };