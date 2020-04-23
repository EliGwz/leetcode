/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
    vector<int> origin;
    vector<int> now;

public:
    Solution(vector<int>& nums) {
        this->origin = vector<int>(nums);
        this->now = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    //    srand(time(0));
        int loc = 0, temp = 0;
        for (int i = 0; i < origin.size(); i++) {
            loc = (rand() % (origin.size() - i)) + i;
            temp = now[i];
            now[i] = now[loc];
            now[loc] = temp;
        }

        return this->now;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

