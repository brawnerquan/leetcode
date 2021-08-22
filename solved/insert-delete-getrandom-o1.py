## OJ: https://leetcode.com/problems/insert-delete-getrandom-o1/
## Author: https://github.com/brawnerquan
## Time: O(1)
## Space: O(n)
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.randset = {}
        self.list = list()

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if(val in self.randset):
            return False
        else:
            self.randset[val] = len(self.list)
            self.list.append(val)
            return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if(val in self.randset):
            self.list[self.randset[val]] = self.list[-1]
            self.randset[self.list[-1]] = self.randset[val]
            del self.randset[val]
            self.list.pop()
            return True
        else:
            return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.choice(self.list)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()