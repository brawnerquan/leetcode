// OJ: https://leetcode.com/problems/palindrome-number/
// Author: https://github.com/brawnerquan
// Time: O(logn) since we divide the number by some constant
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        //check for negative number, if negative, it can't be a palindrome
        if(x < 0)
            return false;
        if(x == 0)//0 base case is always true
            return true;
        if(x % 10 == 0)//base case of if you have the first digit 0, number must be 0
            return false;
        int rev = 0;
        //while the original number is greater than the reverse
            while (x > rev) {
                //extract char from X and put it in rev
                rev = rev * 10 + x % 10;
                x = x / 10;
            }
        //either odd or even number of elems, if odd, we added the middle one to rev so we just remove it and compare
        if (rev == x or rev / 10  == x)
            return true;
        return false;
    }
};