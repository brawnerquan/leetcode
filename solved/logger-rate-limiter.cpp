// OJ: https://leetcode.com/problems/logger-rate-limiter/
// Author: https://github.com/brawnerquan
// Time: O(n) linear time each call of the logger due to searching for the shit in the map, insertion can also cause rebalancing
// Space: O(n) some factor of N will be the space we need to hash
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        logger = unordered_map<string, int>();
    }
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        unordered_map<string, int>::const_iterator elem = logger.find(message);
            if(elem == logger.end()){
                logger.insert({message, timestamp});
                return true;
            }else{
                if(elem->second + 10 <= timestamp){
                    logger[message] = timestamp;
                    return true;
                }else{
                    return false;
                }
            }
        return false;   
    }
private:
    unordered_map<string, int> logger;
};
/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */