// OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author: https://github.com/brawnerquan
// Time: O(n + m), need to iterate through both arrays of input
// Space: O(min(n + m)) hashmap uses smaller array, so whichever is smaller will be the size of the map.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())//if nums 1 is larger we want to use the smaller array to store in the map
            swap(nums1, nums2);
        unordered_map<int, int> intersect;
        int k = 0;
        unordered_map<int, int>::iterator curr_elem;
        for(int i = 0; i < nums1.size(); ++i){//add all the first array elements to the list
            curr_elem = intersect.find(nums1[i]);
            if(curr_elem == intersect.end())
                intersect.insert({nums1[i], 1});
            else
                ++curr_elem->second;
        }
        for(int i = 0; i < nums2.size(); ++i){//now query and see if they're in the list. if they are we need to make sure we haven't added them yet
            curr_elem = intersect.find(nums2[i]);
            if(curr_elem != intersect.end()){
                if(curr_elem->second != INT_MAX and curr_elem->second > 0){//if the elem isnt something we've first seen in the second list
                    nums1[k] = curr_elem->first;
                    ++k;
                    --curr_elem->second;
                }
            }
        }
        return vector(nums1.begin(), nums1.begin() + k);
    }
};
