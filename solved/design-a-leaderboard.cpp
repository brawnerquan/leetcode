// OJ: https://leetcode.com/problems/design-a-leaderboard/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)
// Space: O(n)
class Leaderboard {
public:
    Leaderboard() {
    }
    void addScore(int playerId, int score) {
        unordered_map<int, int>::const_iterator find = playerData.find(playerId);
        if(find == playerData.end()){
            leaderboard.insert({score, playerId});
            playerData[playerId] = score;
        }else{
            //erase the entry
            erase(playerId);
            //now update the score
            playerData[playerId] += score;
            //reinsert with the new score
            leaderboard.insert({playerData[playerId], playerId});
        }
    }
    int top(int K) {
        multimap<int, int>::reverse_iterator end = leaderboard.rbegin();
        int sum = 0;
        for(int i = 0; i < K; ++i){
            sum += end->first;
            ++end;
        }
        return sum;
    }
    void reset(int playerId) {
        erase(playerId);
        playerData[playerId] = 0;
    }
private:
    unordered_map<int, int> playerData;
    multimap<int, int> leaderboard;
    void erase(int playerId){
        pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iterator_pair = leaderboard.equal_range(playerData[playerId]);
        //erase score playerid pair in the multimap
        for(multimap<int, int>::iterator it = iterator_pair.first; it != iterator_pair.second; ++it){
            if(it->second == playerId){
                leaderboard.erase(it);
                break;
            }
        }
    }
};
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

 /*much slower sorting based solution
 class Leaderboard {
 public:
     Leaderboard() {

     }

     void addScore(int playerId, int score) {
         unordered_map<int, int>::const_iterator find = leaderboard.find(playerId);
         if(find == leaderboard.end())
             leaderboard[playerId] = score;
         else
             leaderboard[playerId] += score;
     }

     int top(int K) {
         vector<int> top_k;
         int i = 0;
         for(unordered_map<int, int>::iterator it = leaderboard.begin(); it != leaderboard.end(); ++it){
             top_k.push_back(it->second);
         }
         sort(top_k.begin(), top_k.end());
         int sum = 0;
         for(i = 0; i < K; ++i){
             sum += top_k[top_k.size() - i - 1];
         }
         return sum;
     }

     void reset(int playerId) {
         leaderboard[playerId] = 0;
     }
 private:
     unordered_map<int, int> leaderboard;
 };

 /**
  * Your Leaderboard object will be instantiated and called as such:
  * Leaderboard* obj = new Leaderboard();
  * obj->addScore(playerId,score);
  * int param_2 = obj->top(K);
  * obj->reset(playerId);
  */
