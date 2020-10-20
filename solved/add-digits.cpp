// OJ: https://leetcode.com/problems/add-digits/
// Author: https://github.com/brawnerquan
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        if(num == 0)//since num % 9 could == 0 but the digital root isnt 0 for num == 0
            return 0;
        if(num % 9 == 0)//see, num % 9 should actually be 9
            return 9;
        return num % 9;//otherwise just return the mod, could be sped up by storing mod maybe but im lazy
    }
};
//for whatever reason the digital root follows the pattern of mod 9 
//Naive solution
//     int addDigits(int num) {
//         while(num / 10 != 0){
//             num = sum_digits(num);
//         }
//         return num;
//     }
//     int sum_digits(int num){
//         int sum = 0;
//         while(num != 0){
//             sum += num % 10;
//             num = num / 10;
//         }
//         return sum;
//     }