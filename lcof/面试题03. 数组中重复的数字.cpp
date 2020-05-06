class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (nums[i] != i) {
                int temp = nums[nums[i]];
                if (temp == nums[i]) return temp;
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        return 0;
    }
};