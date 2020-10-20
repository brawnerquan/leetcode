// OJ: https://leetcode.com/problems/reverse-integer/
// Author: https://github.com/brawnerquan
// Time: O(logn) since we divide by a constant factor multiple times
// Space: O(1) we always need an int for the solution. does not scale with n
#include <limits.h>
class Solution {
public:
    int reverse(int x) {
        int mod_val = x % 10;
        int rev = 0;
            while (x != 0) {
                //check for integer overflow before multiplying                
                if (mod_val > 0) {
                    if (rev > (INT_MAX - mod_val)/10)
                            return 0;
                }else{
                    if(rev < (INT_MIN - mod_val)/10)
                            return 0;
                }   
                rev = rev * 10 + mod_val;
                x = x / 10;
                mod_val = x % 10; 
            }
        return rev;
    }
};