// OJ: https://leetcode.com/problems/happy-number/
// Author: https://github.com/brawnerquan
// Time: O(logn)
// Space: O(logn)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        string num;
        while(seen.find(n) == seen.end()){
            if(n == 1)
                return true;
            seen.insert(n);
            num = to_string(n);
            n = 0;
            for(int i = 0; i < num.length(); ++i){
                n += pow(num[i] - '0', 2);
            }
        }
        return false;
    }
};

/* recursive solution
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        return findHappy(seen, n);
    }

    bool findHappy(unordered_set<int> &seen, int n){
        if(n == 1)
            return true;
        string num = to_string(n);

        if(seen.find(n) != seen.end())
            return false;
        seen.insert(n);
        n = 0;
        for(int i = 0; i < num.length(); ++i){
            n += pow(num[i] - '0', 2);
        }
        return findHappy(seen, n);
    }

};
*/
