/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
public:
    int size;
    unordered_map<int, int> bl;
    Solution(int n, vector<int>& blacklist) {
        size = n - blacklist.size();
        int last = n-1;
        for (int i=0; i<blacklist.size(); i++) {
            int value = blacklist[i];
            bl[value] = 1;
        }

        for (int i=0; i<blacklist.size(); i++) {
            int value = blacklist[i];
            if (value >= size) {
                continue;
            }
            while (bl.count(last))
            {
                last--;
            }
            
            bl[value] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand() % size;
        if (bl.count(index)) {
            return bl[index];
        } else {
            return index;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

