// OJ: https://leetcode.com/problems/invalid-transactions/
// Author: https://github.com/brawnerquan
// Time: O(n^2) long ass question with little reward lol
// Space: O(n)
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> trans_map;
        vector<bool> suspicious(transactions.size(), false);
        vector<string> answer;
        size_t string_find;
        unordered_map<string, vector<tuple<int, string, int>>>::const_iterator map_find;
        string name, city;
        int time, amount;
        bool sus;
        for(int i = 0; i < transactions.size(); ++i){
            sus = false;
            //first get all the data
            string_find = transactions[i].find(',');
            name = transactions[i].substr(0, string_find);
            time = stoi(transactions[i].substr(string_find + 1, (string_find = transactions[i].find(',', string_find + 1))));
            // cout << time << endl;
            amount = stoi(transactions[i].substr(string_find + 1, (string_find = transactions[i].find(',', string_find + 1))));
            // cout << amount << endl;
            city = transactions[i].substr(string_find + 1, (string_find = transactions[i].find(',', string_find + 1)));
            // cout << city << endl;
            map_find = trans_map.find(name);
            //if there are no recorded transactions under this user
            if(map_find == trans_map.end()){
                if(amount > 1000){
                    answer.push_back(transactions[i]);
                    sus = true;
                }
            }else{//if there are transactions under this user we have to check everything now :0
                for(int j = 0; j < map_find->second.size(); ++j){
                    //if the time is in the 120 minute range, we have to make sure the cities match
                    if(get<0>(map_find->second[j]) - 60 <= time and time <= get<0>(map_find->second[j]) + 60){
                        if(city != get<1>(map_find->second[j])){//if they don't match we gotta add it to the sus transactions
                            //check if the thing that made this transaction sus is marked as sus already. if not, add it to the list
                            if(suspicious[get<2>(map_find->second[j])] == false){
                                suspicious[get<2>(map_find->second[j])] = true;
                                answer.push_back(transactions[get<2>(map_find->second[j])]);
                            }
                            if(sus == false)
                                answer.push_back(transactions[i]);
                            sus = true;
                        }else{//in case they do match but the amount is too high
                            if(amount > 1000){
                                if(sus == false)
                                    answer.push_back(transactions[i]);
                                sus = true;
                            }
                        }
                    }else{//if the time is out of the time frame then we just check amount
                        if(amount > 1000){
                            if(sus == false)
                                answer.push_back(transactions[i]);
                            sus = true;
                        }
                    }
                }
            }
            suspicious[i] = sus;
            trans_map[name].push_back({time, city, i});//we add no matter what
        }
        return answer;
    }
};
