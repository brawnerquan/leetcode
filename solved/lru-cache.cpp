// OJ: https://leetcode.com/problems/lru-cache/
// Author: https://github.com/brawnerquan
// Time: O(1)
// Space: O(n) where n is the capacity
class LRUCache {
public:
    LRUCache(int capacity) {
        cache = vector<pair<int, Node *>>(capacity);
        cache_avail = capacity;

        lru_front = nullptr;
        lru_back = nullptr;
    }

    int get(int key) {
        finder = cache_map.find(key);
        if(finder == cache_map.end()){
            return -1;
        }

        lru_update(finder->second);
        return cache[finder->second].first;
    }

    void put(int key, int value) {
        if((finder = cache_map.find(key)) != cache_map.end()){//if we can find the key in the map
            //update the value and then
            cache[finder->second].first = value;
            lru_update(finder->second);
        }else if(cache_avail > 0){
            --cache_avail;
            //create new node and add it to the list
            Node *new_node = new Node;
            new_node->prev = nullptr;
            new_node->cache_key = cache_avail;
            new_node->client_key = key;
            if(lru_front == nullptr){
                new_node->next = nullptr;
                lru_front = new_node;
            }else{
                new_node->next = lru_back;
                lru_back->prev = new_node;
            }
            lru_back = new_node;

            cache_map[key] = cache_avail;
            cache[cache_avail] = {value, new_node};//new_node will never change

        }else{
            evict(key, value);
        }
    }

    void lru_update(int cache_key){
        //if front and back are the same we dont need to update the list
        if(lru_front == lru_back)
            return;
        //move that node to the back of the LRU list and fix pointers
        Node *curr_node = cache[cache_key].second;
        //if curr_node the back, we don't need to update anything
        if(curr_node == lru_back)
            return;

        //set the next node's prev to whats behind us, set prev nodes next to curr's next
        if(curr_node != lru_front){
            curr_node->next->prev = curr_node->prev;
        }else{//if the next is null that means we're at the front so we gotta fix the lru_front
            lru_front = curr_node->prev;
            lru_front->next = nullptr;
        }
        //at this point, curr can't be the back of the list so prev must exist
        curr_node->prev->next = curr_node->next;//either next exists which is fine or we're the front

        //update the back;
        lru_back->prev = curr_node;
        //now move curr_node to the back
        curr_node->prev = nullptr;
        curr_node->next = lru_back;
        lru_back = curr_node;
    }

    void evict(int key, int value){
        //move the front to the back, only if the front and back arent equal
        Node *curr_node = lru_front;
        if(lru_front != lru_back){
            lru_front = lru_front->prev;
            lru_front->next = nullptr;
            lru_back->prev = curr_node;
            curr_node->next = lru_back;
            lru_back = curr_node;
            lru_back->prev = nullptr;
        }

        //update the cache_map so the client cant use that key that was freed
        cache_map.erase(curr_node->client_key);
        //update the cache_map so the new client key maps to the cache_key
        cache_map[key] = curr_node->cache_key;
        //get LRU cache key and change the value at that location
        cache[curr_node->cache_key].first = value;//the pointer never changes so no need to change it
        //cache key never changes but client key does
        curr_node->client_key = key;
    }

    ~LRUCache(){

        Node *temp_node;
        while(lru_front != nullptr){
            temp_node = lru_front->next;
            delete lru_front;
            lru_front = temp_node;
        }
    }

private:
    struct Node {
        Node *next;
        Node *prev;
        int cache_key;
        int client_key;
    };
    vector<pair<int, Node *>> cache;
    unordered_map<int, int> cache_map;
    unordered_map<int, int>::const_iterator finder;
    Node *lru_front;
    Node *lru_back;
    int cache_avail;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
