// OJ: https://leetcode.com/problems/largest-divisible-subset/
// Author: https://github.com/brawnerquan
// Time: O(N^2)
// Space: O(N) just an auxillary array of the structs that contain the necessary info to build the LDS backwards
/*
sample test cases: 
input                | expected
[1, 5, 7, 9, 12]       [1] or any of the other ones of size 1
[1, 5, 10, 15, 20]      [1, 5, 10, 20]
if 1 is included it's part of the subset for sure
note: each subset is built off the smalles non 1 integer? 
*/
const int NO_ONE = -1;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0)
            return nums;
        //sort to guarentee that if the new prospective insert is divisible by the max it can be inserted
        sort(nums.begin(), nums.end());
        vector<lds_pair> lds;
        int longest_lds = 1;
        int longest_lds_index = 0;
        for(int i = 0; i < nums.size(); i++){
            //begin by inserting the current elem as it is largest known divisible subset
            lds_pair new_lds_pair;
            new_lds_pair.my_length = 1;
            new_lds_pair.behind_me = NO_ONE;
            new_lds_pair.max_divisor = nums[i];
            lds.push_back(new_lds_pair);
            //now we have to look back and see if there is a bigger one that has a common divisor
            for(int j = 1; j <= i; j++){
                if(nums[i] % lds[i - j].max_divisor == 0 or lds[i - j].max_divisor % nums[i] == 0){
                    if(lds[i].my_length < lds[i - j].my_length + 1){
                        //track the previous element behind me and increase the LDS length
                        lds[i].my_length = lds[i - j].my_length + 1;
                        lds[i].behind_me = i - j;//store the index where this LDS is being built from
                        lds[i].max_divisor = lds[i - j].max_divisor;//grab max
                        //since we're making a bigger LDS, check if this LDS is better than the current best
                        if(lds[i].my_length > longest_lds){
                            longest_lds = lds[i].my_length;
                            longest_lds_index = i;
                        }
                    }else{//if not we just move on
                        continue;
                    }
                    //if curr elem is greater than the max divisor, it must be the new max divisor for this subset
                    //or if the min_divisor is 1, we need to update it since 1 divides everything
                    if(nums[i] > lds[i].max_divisor)
                        lds[i].max_divisor = nums[i];
                }
            }
        }
        // print_vector(lds);
        vector<int> lds_solution(longest_lds);
        build_lds(nums, lds, lds_solution, longest_lds, longest_lds_index);
        return lds_solution;
    }
private:
    struct lds_pair{
        int behind_me;
        int my_length;
        int max_divisor;  
    };
    // void print_vector(vector<lds_pair> vec){
    //     for(int i = 0; i < vec.size(); i++){
    //         cout << vec[i].behind_me << ", ";
    //     }
    //     cout << endl;
    // }
    void build_lds(vector<int> &nums, vector<lds_pair> &lds_info, vector<int> &lds, int length, int index){
            //while there are still indicies to keep following back
            while(index != NO_ONE){
                lds[length - 1] = nums[index];
                length--;
                index = lds_info[index].behind_me;
            }
    }
};