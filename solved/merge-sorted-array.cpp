// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: https://github.com/brawnerquan
// Time: O(n + m)
// Space: O(1) ~ done inplace
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //check base cases
        if(m == 0){
            nums1 = nums2;
            return;
        }else if(n == 0){
            return;
        }
        m--;
        n--;
        while(m + n + 1 >= 0){
            if(n < 0){//we've finished looking at all nums in 2nd array, we're done
                return;
            }else if(m < 0){//finished all the nums in the first array, so copy the remaining in the 2nd
                swap_ranges(nums2.begin(), nums2.begin() + n + 1, nums1.begin());
                return;
            }
            if(nums1[m] < nums2[n]){
                nums1[m + n + 1] = nums2[n];
                n--;
            }else{
                nums1[m + n + 1] = nums1[m];
                m--;
            }
        }
    }
    // void swap(vector<int>& nums1, int m, vector<int>& nums2, int n){
    //     int temp = nums1[m];
    //     nums1[m] = nums2[n];
    //     nums2[n] = temp;
    // }
};
//             if(nums2_i >= n){//we've finished looking at all nums in 2nd array, we're done
//                 return;
//             }else if(nums1_i >= n + m){
//                 swap_ranges(nums2.begin() + nums2_i, nums2.end(), nums1.begin() + next_index);
//                 return;
//             }