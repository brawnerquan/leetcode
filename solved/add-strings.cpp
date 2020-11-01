// OJ: https://leetcode.com/problems/add-strings/
// Author: https://github.com/brawnerquan
// Time: O(n) just one pass to add everything up
// Space: O(n) could be done in place theoretically, but you would need to expand the biggest string by 1
// note: i did a cool trick with pointers and cstrings to get around having to save extra space in the front of the string
/*
example:
num1: 325
num2: 123
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        //create string of max length
        string sum(max(num1.length(), num2.length()) + 1, 0);
        for(int i = 0; i < sum.length() - 1; ++i){
            if(i >= num2.length())
                carry = num1[num1.length() - 1 - i] - '0' + carry;
            else if(i >= num1.length())
                carry = num2[num2.length() - 1 - i] - '0' + carry;
            else//there is a numner in both strings to be processed
                carry = num1[num1.length() - 1 - i] - '0' + num2[num2.length() - 1 - i] - '0' + carry; //carries over the last place's addition
             if(carry > 9){
                sum[sum.length() - 1 - i] = (carry % 10) +'0';
                carry = 1;
            }else{
                sum[sum.length() - 1 - i] = carry +'0';
                carry = 0;
            }
        }
        //add the final front 1 if we've got a carry
        if(carry == 1){
            sum[0] = '1';
            return sum;
        }
        return sum.c_str() + 1;
    }
};
