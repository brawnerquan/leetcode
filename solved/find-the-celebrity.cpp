// OJ: https://leetcode.com/problems/find-the-celebrity/
// Author: https://github.com/brawnerquan
// Time: O(n) n to find the candidate celebrity and then n to verify if they're a celeb or not. can be sped up using caching
// Space: O(1) no new space was allocated
// Note: the caching approach overloads the knows api to first check if a request to it is stored in the cache and if it isnt it
// makes the request and then stores the result in the cache.
/* The knows API is defined for you.
      bool knows(int a, int b); */
class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0)
            return -1;
        else if(n == 1)
            return 1;
        int celeb_candidate = 0;
        for(int i = 1; i < n; ++i){
            if(knows(celeb_candidate, i))
                celeb_candidate = i;
        }
        //if there are more than 1 or 0 candidates remaining, there is no celebrity. if there is one, we must verify they don't know anyone
        for(int i = 0; i < n; ++i){
            if(celeb_candidate != i){
                if(knows(celeb_candidate, i))
                    return -1;
                if(!knows(i, celeb_candidate))
                    return -1;
            }
        }
        return celeb_candidate;
    }
private:
    void print_vector(vector<int> vec){
            for(int i = 0; i < vec.size(); i++){
                    cout << vec[i] << ", ";
            }
            cout << endl;
    }
//     void print_vector(vector<vector<int>> vec){
//         for(int i = 0; i < vec.size(); i++){
//             for(int j = 0; j < 2; j++){
//                 cout << vec[i][j] << ", ";
//             }
//         }
//         cout << endl;
//     }
};

//SLOW VERSION
// OJ: https://leetcode.com/problems/find-the-celebrity/
// Author: https://github.com/brawnerquan
// Time: O(n^2) but kinda optimized but still slow af
// Space: O(n)
/* The knows API is defined for you.
      bool knows(int a, int b); */
class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0)
            return -1;
        else if(n == 1)
            return 1;
        vector<int> candidates(n);
        iota(candidates.begin(), candidates.end(), 0);
        for(int i = 0; i < n; ++i){
            for(auto j = candidates.begin(); j != candidates.end(); ++j){
                //dont look at whether or not they know themselves
                if(i != *j){
                    if(!knows(i, *j)){//if they dont know this person, this person couldn't be the celebrity, so remove them from the list
                        j = candidates.erase(j) - 1;
                    }
                }
            }
        }
        //if there are more than 1 or 0 candidates remaining, there is no celebrity. if there is one, we must verify they don't know anyone
        if(candidates.size() == 1){
            for(int i = 0; i < n; ++i){
                if(candidates[0] != i)
                    if(knows(candidates[0], i))
                        return -1;
            }
            return candidates[0];
        }
        return -1;
    }
private:
    void print_vector(vector<int> vec){
            for(int i = 0; i < vec.size(); i++){
                    cout << vec[i] << ", ";
            }
            cout << endl;
    }
//     void print_vector(vector<vector<int>> vec){
//         for(int i = 0; i < vec.size(); i++){
//             for(int j = 0; j < 2; j++){
//                 cout << vec[i][j] << ", ";
//             }
//         }
//         cout << endl;
//     }
};
