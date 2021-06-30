/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    unordered_map<int, int> valToIndex;
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.count(val) == 1) return false;
        else {
            valToIndex[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valToIndex.count(val) == 0) return false;
        else {
            valToIndex[nums[nums.size()-1]] = valToIndex[val];
            nums[valToIndex[val]] = nums[nums.size()-1];
            valToIndex.erase(val);
            nums.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

