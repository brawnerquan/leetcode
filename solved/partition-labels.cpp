// OJ: https://leetcode.com/problems/partition-labels/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitions;
        //don't need to init as non seen characters will never be touched
        int last_seen[26];
        //populate array of last time we've seen a character
        for(int i = 0; i < s.length(); ++i){
            last_seen[s[i] - 'a'] = i;
        }
        int partition_count = 0;
        int base = 0;
        //push back a partition of size 0 to start
        partitions.push_back(-1);
        for(int i = 0; i < s.length(); ++i){
            //subtract 1 from i so it is the nth number of the string
            //so if we're at i - 1
            if(i == base + partitions[partition_count]){//base + size of current partition
                base = base + partitions[partition_count];
                //push back a new partition of size 0
                partitions.push_back(0);
                ++partition_count;
            }
            partitions[partition_count] = max(partitions[partition_count], last_seen[s[i] - 'a'] + 1 - base);
        }
        return partitions;
    }
};
