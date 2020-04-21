# leetcode 解题思路
## 探索初级算法
### 数组
#### 26.删除排序数组中的重复项

- 数组长度为1时直接返回原数组
- 一次遍历，两个指针p1 p2，从第二个元素开始，p2如果和p2 - 1元素相同，p1不动，p2后移；p2如果和p2 - 1不同，将p2的值赋值给p1所指元素，p1和p2都后移

#### 122.买卖股票的最佳时机 II

- 数组长度为1时直接返回0
- 一次遍历，从第二天开始，和前一天的价格比较，只要当天的价格高于前一天的价格，就加入profit中

#### 189.旋转数组

- 将一个数组右移k位等价于：1. 把整个数组逆序；2. 将前k%n个元素逆序；3. 将剩余的元素逆序

#### 217.存在重复元素

- 用unordered_set，底层为哈希表实现，查找是否已经在集合即可

#### 136.只出现一次的数字

- **位运算**
- 相同的数异或（^)为0，而且异或运算符合交换律和结合律

#### 350.两个数组的交集 II

- 遍历一个数组，用unordered_map计数其中一个数组的元素出现次数，遍历另外一个数组，在之前生成的map中查找元素并使得计数减一，减到0时将该元素从map中删除

#### 66.加一

- 先从末位+1判断是否产生进位，再一位一位往上重复，最后如果还有进位就要在头部插入一个1

#### 283.移动零

- 双指针，一个指针p2遍历整个数组，一个指针p1记录当前第一个0元素的位置，当p2遇到非0元素时，将p1和p2交换，p1和p2都指向下一个；当p2遇到0元素时，p1不动，p2下一个

#### 1.两数之和

- 一次遍历，用unordered_map查找(target - 当前元素)是否在map中，如果存在，直接返回两个数的下标，如果不存在，就将<当前元素, 下标>插入map中

#### 36.有效的数独

- 一次两轮for循环来查询每个格子是否同时满足三个条件（横、纵、小格）
- 关键是如何将i,j和三种情况的横纵坐标对应上，对应一行：`board[i][j]`；对应一列：`board[j][i]`；对应一个3×3小格：`board[i/3*3+j/3][i%3*3+j%3]`
- **位运算**：用一个9bits二进制数X来记录该行/列/小格中是否已有该数字，用移位运算和与运算来更新该数X 

#### 48.旋转图像

- 一次两轮for循环完成
- 可将n×n矩阵拆成一圈一圈来看，对于每圈图像来说，就是顺时针旋转四个长度为n-1的矩形，只需要声明一个temp变量，将四个矩形对应的元素循环赋值
- `matrix[i][j]` -> `matrix[j][n - 1 - i]` -> `matrix[n - 1 - i][n - 1 - j]` -> `matrix[n - 1 - j][i]` -> `matrix[i][j]`
- for循环的次数
  ```cpp
    for (int i = 0; i < (n+1)/2; i++) {
        for (int j = i; j < n-1-i; j++) {}}
  ```

### 字符串
#### 344.反转字符串

- 双指针，一个指向头一个指向尾，交换元素后向字符串中间移动

#### 7.整数反转

- 遍历输入x的每一位
- 用x%10取得x的个位数字，该个位数字为result的最高位，每次循环令`result = result*10 + x%10`，并将x的末位数字去掉（`x /= 10`）
- 提前检查result*10是否会大于INT_MAX或小于INT_MIN

#### 387.字符串中的第一个唯一字符

- 遍历字符串，可以用unordered_map，但是因为固定26个小写字母，所以用int[26]数组会更快，记录各个字母出现的次数
- 再次遍历字符串，找到第一个次数为1的下标，返回

#### 242.有效的字母异位词

- 遍历字符串，记录26个字母出现的次数，用字符串a的记录减去字符串b的记录，如果还有剩余的次数，则不是字母异位词

#### 125.验证回文串

- 将非数字和字母的符号跳过，比较头尾元素是否相同

#### 8.字符串转换整数-atoi

- **状态机**的思想，有四个状态，分别为：start，signed（符号），in_number，end，根据接收的字符切换到不同的状态，对读进来的字符进行计算
- **正则表达式**：`^[\+\-]?\d+`

| 符号   | 意义                     |
| :----- | :----------------------- |
| ^      | 匹配字符串开头           |
| [\+\-] | 代表一个+字符或-字符     |
| ?      | 前面一个字符可有可无     |
| \d     | 一个数字                 |
| +      | 前面一个字符的一个或多个 |
| \D     | 一个非数字字符           |
| *      | 前面一个字符的0个或多个  |

#### 28.实现strStr() --- KMP算法

- [KMP算法](https://www.zhihu.com/question/21923021/answer/281346746)，其实也是**状态机**的思想，如果needle当前元素和haystack当前元素不匹配，就将指向needle元素的指针跳回到之前的某个状态，指向haystack的不变，needle中每个元素应跳回的状态存在next数组中
- 注意**无符号数**和**有符号数**比较，会将有符号数转成无符号数再比较，而string.length()返回的是一个**无符号数**

#### 38.外观数列

- 遍历迭代字符串s，双指针记录重复元素的值和长度，叠加到新建的字符串temp中，遍历完s之后将temp赋值为新的s，再次遍历字符串s

#### 14.最长公共前缀

- 由于字符串数组较多，采用分治的思想，一种是将字符串数组递归分组，计算两两字符串的公共前缀，令一种是选出字符串数组中最短的字符串，该字符串也是最长公共前缀的最长可能结果，将该字符串二分，如果`s[1...mid]`是所有串的前缀，说明我们可以再在`s[mid+1...j]`中找，如果`s[1...mid]`不是所有串前缀，说明我们可以在`s[1...mid]`中寻找它们的公共前缀
- **前缀树**，一个多叉树（每个节点有26个指针，对应26个字母），一个root，根据要插入的word，一层一层向下建树

### 链表

#### 237.删除链表中的节点

- 没有head指针传入，只给了要删除的那个节点，所以不能直接删除节点，只能将目标节点之后的值一个一个向前赋值，最后删除末尾节点
- 需要一个prev指针指向倒数第二个节点，将prev->next也就是最后一个节点释放掉，然后`prev->next = NULL;`

#### 19.删除链表的倒数第N个节点

- 设置双指针，一个指针为p遍历整个链表，一个指针target指向(p-n-1)的位置，当p到达末尾NULL时，删除target+1位置的节点

#### 206.反转链表

- 就地逆置，声明一个新的链表头，每次取原链表头的节点插入到新链表头之后
- 需要两个指针prev, head，分别指向原链表的第1个和第2个节点

#### 21.合并两个有序链表

- 指针l1,l2分别指向两个链表中尚未合并的链表头，用newHead作为合并后链表的头指针，用prev指向已合并的链表的最后一个元素
- 在l1和l2指向的元素中挑选较小的值，接到prev之后，并将l1或l2后移，直到l1或者l2指向nullptr，将prev->next指向l1,l2中非空的结点，后续元素就全部接入新链表了

#### 234.回文链表

- 遍历一遍链表得到链表的长度，如果长度为偶数，直接再遍历链表，栈空时入栈，栈不空时比较栈顶元素和当前元素，相同弹栈，不同压栈，看遍历之后栈是否为空；如果长度为奇数，在第二次遍历到正中间的元素时，不压栈也不弹栈直接跳过到下一个结点
- 快慢指针：fast走两步，slow走一步，移动指针的同时对前半部分进行反转，最后比较前后两个链表 [题解](https://leetcode-cn.com/problems/palindrome-linked-list/solution/javashi-xian-kuai-man-zhi-zhen-fan-zhuan-qian-ban-/)

#### 141.环形链表

- **快慢指针**，慢指针每次走一步，快指针每次走两步，如果存在环，快指针会遇到慢指针，如果不存在环，快指针会先一步到末尾nullptr

### 树

#### 104.二叉树的最大深度

- 递归：若当前结点为空，返回深度为0，若当前结点不为空，返回左右子树深度的较大值+1
- DFS栈：栈内元素为`pair<TreeNode*, depth>`，指针p指向root，优先压p的左子树进栈，左子树到底后，p为空，将当前深度和最大深度比较，更新最大深度，将指针p指向当前的栈顶，并弹栈，当p的右子树扫描完成后，再从栈顶开始，即p的父结点

```cpp
  while(!s.empty() || p != nullptr) {
    while(p != nullptr) {

    }
  }
```

- BFS队列：将root入队，若队列不为空，将队列中所有节点都扫描一遍出队，并将它们的子节点加入队列，每扫描一次队列中全部元素就depth+1（不算后来加入的子节点）

```cpp
  while(!q.empty()) {
    for (i=0; i<q.size(); i++) {

    }
  }
```

#### 98.验证二叉搜索树

- 中序遍历，检查每个输出是否大于上一个输出，若出现递减，则返回false
- 迭代：每个节点的值都要在它的上下界之内

#### 101.对称二叉树

- 层次遍历：用队列进行层次遍历，若结点的子节点为nullptr，也需要加入队列中，然后用一个INT范围之外的值代替，以防该nullptr和存在的镜像节点值对应上，使得本不是镜像对称的二叉树判断为true，检查该层节点序列是否为回文序列
- 递归：两个树镜像对称的条件为：根节点的值相同，且每个树的右子树都与另一个树的左子树镜像对称

#### 102.二叉树的层序遍历

- 用队列层次遍历

#### 108.将有序数组转换为二叉搜索树

- 将有序数组作为二叉搜索树的中序遍历，用队列对该二叉树层次遍历，每次取区间的中间作为根节点和子树的根节点建树

### 排序和搜索

#### 88.合并两个有序数组

- 由于nums[m...n+m]的初始值为0，所以设置双指针从后往前扫描，选择两个数组中较大的数字从数组尾部赋值

#### 278.第一个错误的版本

- 二分法找到Version由good转成bad的转折点
- 注意使用`mid = start + ((end - start) >> 2)`找中点防止溢出

### 动态规划

#### 70.爬楼梯

- **斐波那契数列**：n<3时，返回n；n >= 3时，迭代n-2次，只保留b和a+b的值，并分别赋给a和b

#### 121.买卖股票的最佳时机

- 遍历一遍数组，记录下prices[0...i]中最小的值min，再找prices[i] - min的最大值

#### 53.最大子序和

- **动态规划：** 遍历一遍数组，记录当前子序列的累加和`sum`，如果`sum>0`，说明当前子序列还有继续递增的可能（即使现在`sum`出现了递减的情况），并且每次都保存一个`maxSum`值，如果`sum<0`，说明之前的子序列之中的正数已经完全被负数抵消，此时要丢弃之前的子序列，并讲当前的值赋值给`sum = num[i]`（开始重新计算`sum`），直到遍历完整个数组
- unfinished