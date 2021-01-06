// OJ: https://leetcode.com/problems/word-break/
// Author: https://github.com/brawnerquan
// Time: O(n^3)
// Space: O(??? not sure this solution is wack) but still runs at 95%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> memos;
        unordered_set<string>::const_iterator search_result;
        int dict_size = wordDict.size();
        size_t find_word;
        queue<string> words;
        string front, temp_string, split1, split2;
        words.push(s);
        while(!words.empty()){
            //get the front and remove it permanently
            front = words.front();
            words.pop();
            //now try to remove stuff in the dictonary from the front to see if we can keep splitting it
            for(int i = 0;  i < dict_size; ++i){
                temp_string = front;
                find_word = temp_string.find(wordDict[i]);
                //to continue splitting, there has to be a word in the dictonary that can be removed from the front
                if(find_word == 0){//so if we find we can remove a word from the front we remove it and add the new substring to the q
                    temp_string.erase(find_word, wordDict[i].length());
                    //if we find an empty string, we stop!
                    if(temp_string == "")
                        return true;
                    //search for this string in our map of explored strings
                    search_result = memos.find(temp_string);
                    //if we haven't explored it, add it onto the queue to be explored
                    if(search_result == memos.end()){
                        words.push(temp_string);
                        memos.insert(temp_string);
                    }
                }
            }
        }
        return false;
    }
};

/* slower DP algorithm
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        //set up dict
        for(int i = 0; i < wordDict.size(); ++i){
            dict.insert(wordDict[i]);
        }

        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for(int i = 1; i <= s.length(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] == true and dict.find(s.substr(j, i - j)) != dict.end())
                    dp[i] = true;
            }
        }
        return dp[s.length()];
    }
};
*/
