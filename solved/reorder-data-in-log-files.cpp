// OJ: https://leetcode.com/problems/reorder-data-in-log-files/
// Author: https://github.com/brawnerquan
// Time: O(M * NlogN) where M is the length of the longest log as worst case we scan through the entire log when the comparator is called
// Space: O(logN) which is the space usage of .sort(). Does not need to allocate new space for the strings as they are passed by reference
};
class Solution {
public:
    enum type {
        LETTER = 1,
        NUMBER = 2,
    };
    /*if STR2 should be behind str1, return TRUE. if str1 should be behind str2 return FALSE*/
    static bool compare_str(const string &str1, const string &str2){
        size_t str1_curr = str1.find(' ') + 1;
        size_t str2_curr = str2.find(' ') + 1;
        type str1_type = getType(str1[str1_curr]);
        type str2_type = getType(str2[str2_curr]);
        //number goes after letter so return true 
        if(str1_type == LETTER and str2_type == NUMBER)
            return true;
        //number number case, keep it as is
        if(str1_type == NUMBER and str2_type == NUMBER)
            return false;
        //number letter case- NUMBER DOES NOT GO BEFORE LETTER SO RETURN FALSE
        if(str1_type == NUMBER and str2_type == LETTER)
            return false;
        //letter letter case, now we sort lexicographically. this code can be written more conscisely with like one less comparsion but this is more readable
        while(str1_curr != str1.size()){//technically you should consider casting all chars to lowercase but not important here
            if(str2_curr == str2.size())//str1 is longer than str2, but we've been equivalent going up to this
                return false;//str2 should go before str1 as it is shorter but equivalent
            if(str1[str1_curr] != str2[str2_curr])//if the letters dont match, we return the comparison of them
                return str1[str1_curr] < str2[str2_curr];
            str1_curr++;
            str2_curr++;
        }
        //if we're here, the two strings are equivalent or str1 is shorter than str2
        if(str2_curr != str2.size())//if str1 is shorter than str2, we wont be at the end of str2
            return true;//return true as str1 is shorter but equivalent up to that point than s2, so it is lexiographically less 
        //if not, that means we've got two equivalent strings and we need to check the identifier
        //reset back to the front
        str1_curr = 0;
        while(str1[str1_curr] != ' '){
            //str1 identifier is longer, so str2 should go before str1
            if(str2[str1_curr] == ' ' or str1[str1_curr] > str2[str1_curr])//or if str1 is higher than str2 return false as str2 should go should go before 
                return false;
            if(str1[str1_curr] < str2[str1_curr])//if str2 is higher than str1, str1 shoudl go first so return true
                return true;
            str1_curr++;
        }
        //if we're here, str1 is shorter than str2 since identifiers are unique, so str1 should be infront of str2
        return true;
    }
    static type getType(char c){
        if('A' <= c and c <= 'z')//we have a letter log
            return LETTER;    
        else//digit log
            return NUMBER;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), compare_str);
        return logs;
    }
};