// OJ: https://leetcode.com/problems/string-compression/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1)
            return 1;
        int compressed_length = 0;
        int curr_length = 0;
        char curr_char = chars[0];
        for(int i = 0; i < chars.size(); ++i){
            if(chars[i] == curr_char){
                ++curr_length;
            }else{
                chars[compressed_length] = curr_char;
                ++compressed_length;
                //if we are compressing, gotta put the number in
                if(curr_length > 1)
                    append_number(chars, &compressed_length, to_string(curr_length));
                //update tracking variables
                curr_char = chars[i];
                curr_length = 1;
            }
        }
        //now add the final char we were looking at
         chars[compressed_length] = curr_char;
                ++compressed_length;
                //if we are compressing, gotta put the number in
                if(curr_length > 1)
                    append_number(chars, &compressed_length, to_string(curr_length));
        return compressed_length;
    }
    void append_number(vector<char>& chars, int *compressed_length, string curr_length){
        for(int i = 0; i < curr_length.size(); ++i){
            chars[*compressed_length] = curr_length[i];
            ++*compressed_length;
        }
    }
};
