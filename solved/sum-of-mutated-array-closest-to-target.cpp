// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(n) there's probably some DP way to do this questiont so you don't have to keep calculating test values after a certain point... but nah not today
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {  
        return valueSearch(arr, 0, *max_element(arr.begin(), arr.end()), target);
    }
    int testValue(vector<int> arr, int value){
        int size = arr.size();
        for(int i = 0; i < size; ++i){
            if(arr[i] > value)
                arr[i] = value;
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
    int valueSearch(vector<int> &arr, int low, int high, int target) {
        int mid, test_result, diff;
        pair<int, int> lowest_difference = {-1, INT_MAX};
        while(low <= high){
            mid = (low + high) / 2;
            test_result = testValue(arr, mid);
            diff = abs(target - test_result);
            if(diff < lowest_difference.second){
                lowest_difference.first = mid;
                lowest_difference.second = diff;
            }else if(diff == lowest_difference.second){
                if(lowest_difference.first > mid){
                   lowest_difference.first = mid;
                    lowest_difference.second = diff;
                }
            }
            if(test_result == target)
                return mid;
            if(test_result > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return lowest_difference.first;
    }
};
