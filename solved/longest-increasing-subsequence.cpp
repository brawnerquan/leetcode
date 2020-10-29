// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: https://github.com/brawnerquan
// Time: O(nlogn) keep track of the last element of the LIS of size z at index z of the auxillary array.
// Space: O(n) only needed an auxillary array that could be size n at most
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        vector<int> lis;
        vector<int>::iterator searched_index;
        for(int i = 0; i < nums.size(); i++){
            searched_index = lower_bound(lis.begin(), lis.end(), nums[i]);//search index returns area to consider adding to
            //if search is at the end, nums[i] is greater than all the elements, which means we can extend the length of the longest LIS
            if(searched_index == lis.end()){
                lis.push_back(nums[i]);//since we are extending, we go to the lis_length - 1 + 1 index so just lis_length. then we increment
            }else if(*searched_index == nums[i]){//if search equals the element, make sure we dont do anything
                continue;
            }else{//*searched_index must be greater than nums[i]. all elems before must be less than nums[i].
                *searched_index = nums[i];//so we must replace the value as nums[i] can form an identical size LIS using one less element
            }
        }
        return lis.size();
    }
private:
    // void print_vector(vector<int> vec){
    //     for(int i = 0; i < vec.size(); i++){
    //             cout << vec[i] << ", ";
    //     }
    //     cout << endl;
    // }
};


// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: https://github.com/brawnerquan
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        int lis[nums.size()];
        int lis_length = 1;
        for(int i = 0; i < nums.size(); i++){
            lis[i] = 1;
            for(int j = i; j >= 0; j--){
                //if a number behind this one is less than the current, we check if it has a better LIS than what we have stored
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){//if option we have found is better
                        lis[i] = lis[j] + 1;//make it our new LIS
                        if(lis[i] > lis_length)//store the max LIS
                            lis_length = lis[i];
                    }
                }
            }
        }
        return lis_length;
    }
};
