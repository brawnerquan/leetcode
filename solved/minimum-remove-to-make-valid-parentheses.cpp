// OJ: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: https://github.com/brawnerquan
// Time: O(n) two passes required!
// Space: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        string first_pass = "";
        int num_close = 0;
        for(int i = 0; i < s.length(); ++i){
            //if we see an open, just put it on. there should either be nothing or just other opening ones on the stack
            if(s[i] == '('){
                stack.push(i);
                first_pass += s[i];
            }else if(s[i] == ')'){
                //if we have something on the stack, we keep this closing parenthesis.
                if(!stack.empty()){
                    ++num_close;
                    first_pass += s[i];
                    stack.pop();
                }
                //otherwise throw it out
            }else{
                first_pass += s[i];
            }
        }
        s.clear();
        //now since we know the number of open parenthesis we need to keep and all of the extra closing ones have been removed
        for(int i = 0; i < first_pass.length(); ++i){
            if(first_pass[i] == '('){
                if(num_close > 0){
                    s += '(';
                    --num_close;
                }
            }else{
                s += first_pass[i];
            }
        }
        return s;
    }
};
