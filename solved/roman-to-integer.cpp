// OJ: https://leetcode.com/problems/roman-to-integer/
// Author: https://github.com/brawnerquan
// Time: O(n), passes through the roman numeral once
// Space: O(1)
};
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        //need to make it so s[i -1  never == -1]
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) {
                if (s[i - 1] == 'I') {
                    if (s[i] == 'V') {
                        num += 4;
                        s[i]  = '\0';
                    } else if (s[i] == 'X') {
                        num+= 9;
                        s[i]  = '\0';//set it to a null char so it wont be double counted
                    } else {
                        num += 1;//if there was an I but it was never followed by val
                    }
                } else if (s[i - 1] == 'X') {
                    if (s[i] == 'L') {
                        num += 40;
                        s[i]  = '\0';
                    } else if (s[i] == 'C') {
                        num += 90;
                        s[i] = '\0'; //make sure C dosen't get double counted
                    } else {
                        num += 10;
                    }
                } else if (s[i - 1] == 'C') {
                    if (s[i] == 'D') {
                        num += 400;
                        s[i]  = '\0';
                    } else if (s[i] == 'M') {
                        num += 900;
                        s[i]  = '\0';
                    } else {
                        cout << "hello" << endl;
                        num += 100;
                    }
                }
                if (s[i] == '\0') {
                    continue;
                } else if (s[i] == 'V') {
                    num += 5;
                } else if (s[i] == 'L') {
                    num += 50;
                } else if (s[i] == 'D') {
                    num += 500;
                } else if (s[i] == 'M') {
                    num += 1000;
                } 
            } else if (s[i] == 'V') {
                    num += 5;
                } else if (s[i] == 'L') {
                    num += 50;
                } else if (s[i] == 'D') {
                    num += 500;
                } else if (s[i] == 'M') {
                    num += 1000;
                } 
            if (i == s.length() - 1) {
                if (s[i] == 'I') {
                    num += 1;
                } else if (s[i] == 'C') {
                    num += 100;
                } else if (s[i] == 'X') {
                    num += 10;
                }
            }
        }
        return num;
    }
};