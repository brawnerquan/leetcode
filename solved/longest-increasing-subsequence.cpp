// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: https://github.com/brawnerquan
// Time: O(n^2) can be improved to nlogn, but still working on learning how to the nlogn implementation works. will attempt to complete asap
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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        vector<int> lis(nums.size(), 0);
        int lis_length = 1;
        int max_size = nums.size() - 1;
        int searched_index, val_at_index;
        for(int i = 1; i < nums.size(); i++){
            cout << "BEFORE SEARCH" << endl;
            searched_index = binary_search(nums, lis, max_size, 0, lis_length - 1, nums[i]);//search index returns area to consider adding to
            cout << "AFTER SEARCH: " << searched_index <<  endl;
            val_at_index = nums[lis[searched_index]];
            

            if(nums[i] > val_at_index){//if nums is greater, we can potentially increase the LIS at this index
                
                if(lis_length < searched_index + 1){//if this would make a new bigger LIS, we add it
                    lis[searched_index + 1] = i;//store the index (index in nums) of the largest element in this new LIS
                    ++lis_length;
                    cout << "INCREASED LENGTH IS NOW: " << lis_length << endl;
                }else{//otherwise, we're would be making a new one equivalent to the max or something less than the max, so we have to check
                    if(val_at_index < nums[lis[searched_index + 1]])//if the val we're considering adding is smaller, we improve LIS so we replace
                        lis[searched_index + 1] = i;
                    //if not, we don't have an improvement so we just move on
                }
            }else if(nums[i] < val_at_index){//if nums is less than, we can improve the LIS for the size we're at so we replace
                lis[searched_index] = i;
                cout << "VAL_AT_INDEX: " << searched_index << "IS " << lis[searched_index] <<  endl;
            }//if they're equal, we just continue
            
            // cout << "I :" << i << "SEARCH FOUND: " << searched_index << endl;            
            cout << "AFTER ITERATION I: " << nums[i] << " LIS VECTOR LOOKS LIEK THIS:"<<  endl;
            print_vector(lis);
        }
        return lis_length;
    }
    
private:
    //since we store the index of the last element in the LIS of the index size, we gotta actually check the value there
    int binary_search(vector<int> &nums, vector<int> &arr, int max_size, int low, int high, int val){
        int middle;
        
        while(low <= high){
            middle = (low + high) / 2;
            if(nums[arr[middle]] == val){
                return middle;
            }else if(nums[arr[middle]] < val){
                low = middle + 1;
            }else{
                high = middle - 1;
            }
        }
        if(val < nums[arr[middle]])//if the value is less than the place we ended up by
            return max(middle - 1, 0);//make sure we don't return -1 as the index to inspect
        else//if it's greater, make sure we dont return a value outside of the max length
            return min(middle + 1, max_size);
        
        return middle;
    }
    
    void print_vector(vector<int> vec){
        for(int i = 0; i < vec.size(); i++){
                cout << vec[i] << ", ";
        }
        cout << endl;
    }
};


