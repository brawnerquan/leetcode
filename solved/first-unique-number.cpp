// OJ: https://leetcode.com/problems/first-unique-number/
// Author: https://github.com/brawnerquan
// Time: O(n?) idk shitty implementation
// Space: O(n) two stacks
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            add(nums[i]);
        }
    }
    int showFirstUnique() {
        //otherwise find the first element in the queue that is unique
        while(!order.empty() and uniques[order.front()] == false)
            order.pop();
        if(order.empty())
            return -1;
        return order.front();
    }
    void add(int value) {
        if(uniques.find(value) != uniques.end()){
            uniques[value] = false;
        }else{
            uniques.insert({value, true});
            order.push(value);//if it's a unique value we add it to our unique value list
        }
        queue.push(value);
    }
private:
    queue<int> order;
    queue<int> queue;
    unordered_map<int, bool> uniques;
};
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
