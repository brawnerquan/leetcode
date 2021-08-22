// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: https://github.com/brawnerquan
// Time: O(diff) upper bound is the difference between the two array sums
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int diff, target;
        int steps = 0;
        
        //array setup
        int sum1 = 0;
        int floor1 = nums1.size();
        int ceiling1 = floor1 * 6;
        
        int sum2 = 0;
        int floor2 = nums2.size();
        int ceiling2 = floor2 * 6;
        
        int arr1[6] = {0};
        int arr2[6] = {0};
        
        //setup count arrays, get sums
        for(int i = 0; i < nums1.size(); ++i){
            sum1 += nums1[i];
            ++arr1[nums1[i] - 1]; 
        }
        
        for(int i = 0; i < nums2.size(); ++i){
            sum2 += nums2[i];
            ++arr2[nums2[i] - 1]; 
        }
        
        diff = sum2 - sum1;
        
        //if diff is positive, 2 is greater than 1,
        //if 2 is greater than 1, if 2 is at floor and 1 is at max, then can't solve
        //if 1 is greater than 2, if 1 is at floor and 2 is at max, then can't solve
        while(diff != 0){
            
            //if diff greater than 5, start at 5 and move down or go with current diff
            target = min(abs(diff), 5);
            
            //figure out hi and low arrays, check if we can't solve anymore
            if(diff > 0){
                if(sum2 == floor2 and sum1 == ceiling1)
                    return -1;
                make_move(arr1, arr2, sum1, sum2, target);
            }else{
                if(sum1 == floor1 and sum2 == ceiling2)
                    return -1;
                make_move(arr2, arr1, sum2, sum1, target);
            }
            
            ++steps;
            diff = sum2 - sum1;
            
        }
        
        
        return steps;
    }
    
    
    void make_move(int (&lowarr)[6], int (&hiarr)[6], int &lowsum, int &hisum, int target){
        if(target == 0){
            cout << "ERROR: TARGET = 0" << endl;
            return;
        }
        
        //see if we can add anything to low to make the difference up
        for(int i = 6 - target - 1; i >= 0; --i){
            //if we can achieve the target, take the opportunity
            if(lowarr[i] != 0){
                --lowarr[i];
                ++lowarr[i + target];
                lowsum += target;
                return;
            }
        }
        
        //see if we can subtract anything from hi to make the difference up
        for(int i = target; i < 6; ++i){
            //if we can achieve the target, take the opportunity
            if(hiarr[i] != 0){
                --hiarr[i];
                ++hiarr[i - target];
                hisum -= target;
                return;
            }
        }
        //if not possible, recursively try to subtract less
        make_move(lowarr, hiarr, lowsum, hisum, target - 1);
        
    }

};
