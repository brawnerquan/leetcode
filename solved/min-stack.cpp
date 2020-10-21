// OJ: https://leetcode.com/problems/min-stack/
// Author: https://github.com/brawnerquan
// Time: O(1) for all operations
// Space: O(n)
/*this is the two stack implementation that is supposed to be the fastest version, but isn't really faster at least
according to leetcode's timing. probably with bigger datasets and more rigorious testing it is faster but it was a 
good exercise to implement. the other, slightly slower solution augments the stack to include the local_min where 
the local min is defined as the min if the top of the stack was that element. takes a little more storage space than this
implementation but is simpler and a little less nuanced. */
class MinStack {
public:
    MinStack() {   
        head = nullptr;
        min = nullptr;
    }
    void push(int x) {
        if(head == nullptr){
            head = new Node {x, nullptr};
            min = new Stack_Min {x, 1, nullptr};
        }else{
            head = new Node {x, head};
            //if we find a new min, then create a new min stack node
            if(x < min->min)
                min = new Stack_Min {x, 1, min};
            else
                min->min_for++;
        }
    }
    void pop() {
        Node *new_top = head->next_node;
        delete head;
        head = new_top;
        Stack_Min *next_min = min->next_min;
        //if this is the min for one more time, that means when we remove it is no longer the min, so remove it as the min stack as we pop
        if(min->min_for == 1){
            delete min;
            min = next_min;
        }else{//otherwise, decrement the min counter
            min->min_for--;
        }
    }
    int top() {
        return head->val;