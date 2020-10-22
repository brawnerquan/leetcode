// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Author: https://github.com/brawnerquan
// Time: O(nlogn), gotta sort and insert and extract from the heap a ton
// Space: O(n) to store the heap data
class Solution {
    const int BEGIN = 0;
    const int END = 1;
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size() == 0)
            return 0;
        //augmented sort with custom comparator to sort be first index to get the vector ordered by beginning time
        sort(intervals.begin(), intervals.end(), [](vector<int> &left, vector<int> &right){return left.at(0) < right.at(0);});
        //now pass through and keep track of the number of rooms free and the number of rooms we need to allocate
        //need at least one room, this is because we skip the first iteration and just add the ending time of that room on the heap
        int rooms_needed = 1;
        //create min heap to keep track of the room that will be free next
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(int i = 1; i < intervals.size(); i++){
            //push the next ending time on the heap
            min_heap.push(intervals[i - 1][END]);
            //if the next available room is free after the room we're looking at begins, we gotta get another room bruh
            if(min_heap.top() > intervals[i][BEGIN]){
                rooms_needed++;
            }else{//if the room isnt needed, that means that room will be taken by this next meeting, so we gotta pop if off the min_heap
                min_heap.pop();
            }
        }
        return rooms_needed;
    }
};