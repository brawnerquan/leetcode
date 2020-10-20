// OJ: https://leetcode.com/problems/valid-parentheses/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        stack<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' or s[i] == '(' or s[i] == '['){
                stack.push(s[i]);
            }else if(stack.empty()){
                return false;
            }else{
                if(areMatching(stack.top(), s[i]))
                    stack.pop();
                else
                    return false;
            } 
        }
        if(!stack.empty())
            return false;
        return true;
    }
    bool areMatching(char a, char b){ 
        if(a == '(' and b == ')')
            return true;
        else if(a == '{' and b == '}')
            return true;
        else if(a == '[' and b == ']')
            return true;
        else
            return false;
    }
};