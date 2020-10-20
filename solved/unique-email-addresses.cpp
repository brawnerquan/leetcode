// OJ: https://leetcode.com/problems/unique-email-addresses/
// Author: https://github.com/brawnerquan
// Time: O(E) where E is the length of all of the emails combined
// Space: O(E) for the unordered_set
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email_list;
        for(int i = 0; i < emails.size(); i++){
            email_list.insert(preprocess_str(emails[i]));
        }
        return email_list.size();
    }
private:
    string preprocess_str(string str){
        size_t period = str.find(".");
        size_t at = str.find("@");
        //removes all . that are before the @
        while(period != string::npos and period < at){
            str.erase(period, 1);
            period = str.find(".");
            at = str.find("@");
        }
        //removes all shit from + to @
        size_t plus = str.find("+");
        at = str.find("@");
        if(plus != string::npos){
            str.erase(plus, at - plus);
        }
        return str;
    }
};