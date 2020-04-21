/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;

        int maxProfit = INT_MIN, min = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min)
                min = prices[i];
            if (prices[i] - min > maxProfit)
                maxProfit = prices[i] - min;
        }
        return maxProfit;
    }
};
// @lc code=end

