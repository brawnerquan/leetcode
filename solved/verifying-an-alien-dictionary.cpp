// OJ: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Author: https://github.com/brawnerquan
// Time: O(w) where w is the length of all of the words combined 
// Space: O(1) constant space to store the new alphabet
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> alien_dict;
        for(int i = 0; i < 26; i++){
            alien_dict.insert({order[i], i});
        }
        int word_1 = 0;
        int word_2 = 0;
        for(int i = 1; i < words.size(); i++){
            word_1 = 0;
            word_2 = 0;
            while(word_1 != words[i - 1].length()){
                //if we reach the end of word2 before word1, word 2 should go before word1
                if(word_2 == words[i].length() or alien_dict[words[i - 1][word_1]] > alien_dict[words[i][word_2]]) 
                    return false;
                //if word1's char is less than words2 char, that means that we are lexiographically sorted so we return true
                // cout << alien_dict[words[i - 1][word_1]] << alien_dict[words[i][word_2]] << endl;
                if(alien_dict[words[i - 1][word_1]] < alien_dict[words[i][word_2]])
                    break;
                //or, the chars are equal, which means we gotta go againe
                word_1++;
                word_2++;
            }//if we reach the end of word one and all chars match but there is still shit left in word2, we are sorted
        }
        return true;
    }
};