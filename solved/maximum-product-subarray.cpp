// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
//can get space to constant by just keeping track of the previous one by one
//approach was building two dp arrays, one max and one min contiguous subsequence of the array and check all possible ways to extend the min and max contig sub at each index!
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> min_sarray(nums.size());
        vector<int> max_sarray(nums.size());
        int max_prod = nums[0];
        min_sarray[0] = nums[0];
        max_sarray[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            max_sarray[i] = max(nums[i] * max_sarray[i - 1], nums[i]);
            max_sarray[i] = max(max_sarray[i], min_sarray[i - 1] * nums[i]);
            max_prod = max(max_prod, max_sarray[i]);
            min_sarray[i] = min(nums[i] * min_sarray[i - 1], nums[i]);
            min_sarray[i] = min(min_sarray[i], max_sarray[i - 1] * nums[i]);
        }
        return max_prod;
    }
};


//more complicated solution that i wrote that is wayyy more complicated, could be n^2? not exactly sure
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size());
        vector<int> accumulator(nums.size());
        
        int num_negatives = 0;
        int front = 0;

        if(nums[0] == 0){
            accumulator[0] = 1;
            dp[0] = 1;
            front = 1;
        }else{
            accumulator[0] = nums[0];
            dp[0] = nums[0];
        }
        
        if(nums[0] < 0)
            ++num_negatives;
        
        int max_prod = nums[0];
        
        
        
        for(int i = 1; i < nums.size(); ++i){
            //accumulat total product
            accumulator[i] = nums[i] * accumulator[i - 1];
            if(nums[i] == 0){
                dp[i] = 0;
                accumulator[i] = 1;
                num_negatives = 0;
                front = i + 1;
            }else if(nums[i] < 0){            
                ++num_negatives;
                
                if(num_negatives == 1){//havent seen any negatives, cant do anything
                    dp[i] = nums[i];
                }else if(num_negatives % 2 == 0){
                    //if we've seen an even number, can go back until you hit the last one to build a product
                    dp[i] = accumulator[i];
                }else{  
                    //current is negative, if we've seen an odd number of negatives we can build a contiguous
                    //with all that is behind the current index
                    dp[i] = accumulator[i];
                    
                    int counter = front;
                    while(nums[counter] > 0){
                        dp[i] /= nums[counter];
                        ++counter;
                    }
                    dp[i] /= nums[counter];
                    
                }
                           
            }else{ //curent is positive, extend subarray as long as previous is not negative
                if(dp[i - 1] > 0){
                    dp[i] = nums[i] * dp[i - 1];
                }else{
                    dp[i] = nums[i];
                }
                
            }

            max_prod = max(dp[i], max_prod);
        }
               
        return max_prod;
    }
};