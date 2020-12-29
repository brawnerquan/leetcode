// OJ: https://leetcode.com/problems/group-anagrams/
// Author: https://github.com/brawnerquan
// Time: O(nk) where n is the number of input strings and k is the length of the max length one
// Space: O(nk) gotta have room to at least store every string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, int> anagram_map;
        int identifier = 0;
        string count_string;
        unordered_map<string, int>::const_iterator find;
        for(int i = 0; i < strs.size(); ++i){
            count_string = getCountString(strs[i]);
            find = anagram_map.find(count_string);
            if(find == anagram_map.end()){
                anagram_map[count_string] = identifier;
                answer.push_back(vector<string>(1, strs[i]));
                ++identifier;
            }else{
                answer[anagram_map[count_string]].push_back(strs[i]);
            }
        }
        return answer;
    }
    string getCountString(string str){
        int counts[26] = {0};
        string answer = "";
        for(int i = 0; i < str.length(); ++i){
            ++counts[str[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i){
            answer += counts[i];
        }
        return answer;
    }
};

/*solved using string sorting too

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<string> strs_sorted = strs;
        unordered_map<string, int> anagram_map;
        int identifier = 0;
        unordered_map<string, int>::const_iterator find;
        for(int i = 0; i < strs_sorted.size(); ++i){
            sort(strs_sorted[i].begin(), strs_sorted[i].end());
            find = anagram_map.find(strs_sorted[i]);
            if(find == anagram_map.end()){
                anagram_map[strs_sorted[i]] = identifier;
                answer.push_back(vector<string>(1, strs[i]));
                ++identifier;
            }else{
                answer[anagram_map[strs_sorted[i]]].push_back(strs[i]);
            }
        }


        return answer;
    }
};

*/
