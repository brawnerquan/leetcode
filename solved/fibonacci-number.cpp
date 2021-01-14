// OJ: https://leetcode.com/problems/fibonacci-number/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int fib(int n) {
        if(n == 1)
            return 1;
        if(n == 0)
            return 0;
        int n_1 = 0;
        int n_2 = 1;
        int temp;
        for(int i = 2; i <= n; ++i){
            temp = n_2 + n_1;
            n_1 = n_2;
            n_2 = temp;
        }
        return n_2;
    }
};
