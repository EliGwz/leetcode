# leetcode 解题思路

## 剑指Offer

### 面试题03. 数组中重复的数字

- 遍历数组，查看当前位置的元素是否处于正确的位置`nums[i] == i`，如果是，看下一位，如果不是，将当前元素交换到它的正确位置上，再检查新的当前元素的位置是否正确，直到当前位置元素正确。过程中若发现当前位置元素和待交换位置的元素的值相等，说明该值重复，直接返回该值

### 