/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i = 0; i < n; i++) {
            if (isMultiple3(i+1) && isMultiple5(i+1))
                v.push_back("FizzBuzz");
            else if (isMultiple3(i+1))
                v.push_back("Fizz");
            else if (isMultiple5(i+1))
                v.push_back("Buzz");
            else
                v.push_back(to_string(i + 1));
        }
        return v;
    }

    bool isMultiple3(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10);
            n /= 10;
        }

        if (sum % 3 == 0)
            return true;
        else
            return false;
    }

    bool isMultiple5(int n) {
        if (n % 10 == 0 || n % 10 == 5)
            return true;
        else
            return false;
    }
};
// @lc code=end

