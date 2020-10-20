// OJ: https://leetcode.com/problems/most-common-word/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()
class Solution {
    const int BANNED_STR = -1;
public:
    static bool condition(char c){
        if('a' <= c and c <= 'z' or c == ' ')
            return false;
        return true;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if(paragraph == "")
            return paragraph;
        unordered_map<string, int> map;
        //insert banned words in map
        for(int i = 0; i < banned.size(); i++){
            map.insert({banned[i], BANNED_STR});
        }
        //ban the whitespace char as a word and the empty string
        map.insert({" ", BANNED_STR});
        map.insert({"", BANNED_STR});
        //make paragraph lowercase
        for(int i = 0; i < paragraph.size(); i++)              
            paragraph[i] = tolower(paragraph[i]);
        //remove extra punctuation
        replace_if(paragraph.begin(), paragraph.end(), condition, ' ');
        //insert normal words into map
        size_t curr_pos = 0;
        size_t word_begin = 0;//being used as the previous word
        string next_word;
        unordered_map<string, int>::iterator found;
        while(curr_pos != string::npos){
            curr_pos = paragraph.find(' ', curr_pos + 1);
            // cout << "WORD_BEGIN" << word_begin << endl;
            // cout << "CURR_POS" << curr_pos << endl;
            next_word = paragraph.substr(word_begin, curr_pos - word_begin);
            // cout << "WORD: " << next_word << endl;
            found = map.find(next_word);
            if(found == map.end()){
                map.insert({next_word, 1});
            }else{
                if(found->second != -1){
                    // cout << "SECOND OCCURENCE: " << found->second << endl;
                    found->second++;
                    // cout << found->second << endl;
                }
            }
            word_begin = curr_pos + 1;