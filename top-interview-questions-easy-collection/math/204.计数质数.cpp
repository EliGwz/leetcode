/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;

        vector<bool> primes(n, true);
        for (int i = 2; i < sqrt(n); i++) {
            if (primes[i]) {
                for (int j = 2; j * i < n; j++) {
                    primes[j * i] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i])
                count++;
        }
        return count;
    }
};
// @lc code=end

