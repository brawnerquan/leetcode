// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: https://github.com/brawnerquan
// Time: O(n + m) kinda shitty code but whatever
// Space: O(min(n + m))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> intersect;
        vector<int> intersection;
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
            if(curr_elem != intersect.end() and curr_elem->second != -1){//if the elem isnt something we've first seen in the second list
                intersection.push_back(curr_elem->first);
                curr_elem->second = -1;
            }
        }
        return intersection;
    }
};
