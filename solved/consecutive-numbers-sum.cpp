// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: https://github.com/brawnerquan
// Time: O(sqrtN)
// Space: O(1)

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int max_k = sqrt(2 * n + 0.25) - 0.5;
        int count = 0;
        for(int k = 1; k <= max_k; ++k){
            if((2 * n - k * (k + 1)) % (2 * k) == 0)//if x is an integer, we good
              ++count;
        }
        return count;
    }
};
/* stupid solution
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if(n == 1 or n == 2)
            return 1;
        //as you include yourself
        int count = 1;
        long left, right, sum;
        left = n / 2 + 1;
        right = n / 2 - 1;
        //calculate starting triangle sum
        sum = ((left * (left + 1)) / 2) - ((right * (right + 1)) / 2);
        cout << sum << endl;
        while(left >= 0 and right >= 0){
            cout << left << endl;
            cout << right << endl;
            cout << sum << endl;
            if(sum == n){//if our sum is the target then we record we've found
                ++count;
                //then explore by first increasing the sum by decreasing right
                sum += right;
                --right;
            //otherwise we need to evaluate which direction we need to step in and then go from there
            }else if(sum > n){//if we're above the target we gotta decrease our sum so decrement left
                sum -= left;
                --left;
            }else{//otherwise we need to increase our sum to get closer to the target
                sum += right;
                --right;
            }
        }
        return count;
    }
};

*/
