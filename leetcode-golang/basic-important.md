### 数据结构
#### 二叉树
1、94（中序遍历，非递归方式,稳），145（后序遍历，非递归方式）,都先写个递归，然后再写非递归
2、95/96（不同的二叉搜索树，递归方式）
3、103（锯齿形遍历，稳），以及类似的层次遍历（稳，107，要注意[:]是全部赋值，nodes := []*TreeNode{} 这样才是清空），199、二叉树的右视图（稳）
4、110（平衡二叉树，熟悉）、111（二叉树的最小深度）、104（二叉树的最大深度，稳），543（二叉树的距离（直径），这个还不稳，再次出错，因为直径可能出现在左（右）某一个子树的（左右）连接中，所以不是root.Left和root.Right的最大深度之和），226（翻转二叉树，要稳住）、101（对称二叉树，稳）
5、235（二叉搜索树的最近公共祖先，稳）、236（二叉树的最近公共祖先，稳）
6、112（稳，是否存在二叉树路径和==target）
7、98（验证二叉搜索树，需要熟悉）
8、208（实现Trie树）
9、105（稳，从前序和中序遍历构造二叉树，找到rootVal，将preorder和inorder给切分了，然后递归即可）
10、710（熟悉，二叉搜索树中插入一个元素，递归的方式，终止条件root == nil，然后插入）

### 排序
特别是1/3
1、快排
2、归并
3、堆排序
4、无序数组中寻找中位数（最小堆保存前len(nums)/2的数据，然后遍历剩下的，如果比堆顶元素大，则取代，重新调整堆）

### 链表
24、25、每2个/k个节点反转链表（突破，记住nodesLen, prev, cur, next的方法，已经比较稳了）
2、两个链表数相加（回炉，常考，稳）
3、环形链表（快慢指针），相加链表（找到节点之差）
83、删除链表中重复的元素（稳，较简单，重复元素保留1个，因为不需要考虑头结点被删除的情况，直接比较temp和temp.next的值即可）  作为对比：82、删除链表中重复的元素II（重复元素一个都不保留，还需要再熟悉一下，差之毫厘，把一波儿删完，然后继续开始）
41、旋转链表（稳，需要注意k%length==0的情况，直接返回head，不用slow,fast去寻找了）

### 常考题汇总
2、两个链表数相加（稳）
7、整数反转（不要存储哈）
9、回文数（和整数反转一起，稳）
10、最长回文子串，最长回文子串的长度（最简单的动态规划）
11、最长公共前缀

### 字节跳动专项
1、两数之和 --- hash表（稳）   15、三数之和 --- 能理解，要突破   494、目标和（+ -连接数字等于目标和） 要突破，动态规划
2、两数相加 --- 链表操作（稳）dummy节点（和21、合并两个有序链表区分开来）  for循环中l1!=nil和l2!=nil之间的或/与关系   445、两数相加II（链表长度不一样，使用slice冒充的stack实现，且在结果链表中从头部插入）
3、无重复字符的最长子串 --- 两根指针（主要是方法啊，别走偏了）strings.Contains(s[left:right], string(s[right]))
4、寻找两个有序数组的中位数 --- 两根指针（方法要理解）
5、最长回文子串 --- 最简单的动态规划了（多复习）
206、反转链表（稳） ---  但是要注意golang中一个nil指针的声明方式，直接var prev *ListNode即可
42、接雨水（需要突破） --- 两根指针，理解了就容易，从两边i,j维护一个到i,j为止最大的数，然后有下降的地方都会算进来，两边选择小的原因是需要两边都能对得上，蓄住水，如果是大的话不能
53、最大子序列和（需要再熟悉，维护nums[i], local+nums[i], global三者的最大值）
146、LRU Cache（还需要再熟悉，特别是removeFromChain()和addToChain()的异常判定,最近一次居然是在addToChain()的时候少了node.prev = nil,因为要在head前面加node，所以需要指定node.prev为nil,双向指针缺一不可啊）
33、搜索有序数组（需要再熟悉），一定是半边有序，怎么判定左半边还是右半边有序
135、分糖果（需要突破），从两边遍历两次的方法应该掌握，单词遍历的方法需理解
56、合并区间（需要再熟悉），特别是case的判定条件之间的关系
21、合并两个有序链表（稳），23、合并k个排序链表（从两个引申过来的方法可以解决了，稳），88、合并两个有序数组（稳）
93、复原ip地址（需要突破）
25、k个一组反转链表（需要突破）非递归和递归两种方式
215、找出数组中第k大的数（需要再熟悉，对于golang中heap的用法，Less, Swap, Len, Pop, Push，后两者的出入参都是interface{}，特别注意）
121、买卖股票的最佳时机（数组中找到后面值比前面值差的最大值）（稳，对于这种local，global变换的比较熟了）  122买卖股票的最佳时机II（可以多次买卖，想得太复杂了，很简单，就是后一个比前面打，就加上它们之差）
200、岛屿的数量（需要突破），DFS   695、岛屿的最大面积(在200题的基础上进行，熟悉)
84、直方图的最大围成面积（需要突破，只需要找到局部峰值（比下一个数大的当前数），向前处理即可）85、最大矩形（很巧，在84的基础上进行，构建heights数组，循环调用84的方法，查找最大面积）
11、盛最多水的容器（相信自己），两根指针
72、编辑距离（需要突破，比较简单的动规了），动态规划
46、全排列（遇到golang大坑，还在寻求解决，方法要熟悉）、31、下一个排列（方法还要熟悉啊,分三步：
(1)、从后向前找到第一个降序的数字（下标i），是降之后的数字；
(2)、从后向前找到第一个大于该降序数字的数（下标j），然后交换；
(3)、将下标i这个值后面的序列反转）
70、爬楼梯（最简单的动态规划，就不说了）
322、零钱兑换（简单的动态规划，可惜了，要熟悉）
55、跳跃游戏（遍历的办法能实现，但应该熟悉贪心算法，因为我们并不关心每一个位置的剩余步数，只对最远能到达的位置感兴趣，因此对于维护dp数组意义不大）,45、跳跃游戏II（按照I的数组方法也可以做对，但同样应该熟悉贪心算法，维护每次跳跃能到达的最近和最远距离区间，left和right）
440、字典序的第k小数字（真心难，理解）
10、正则表达式匹配（TODO）
143、重排链表（稳，先将链表分成左右两部分，然后将第二部分反转，最后将第二部分间隔插入第一部分），148 链表排序（O(nlgn)的时间复杂度），同样，先分成两部分，然后分别对两部分排序，再合并
26、删除排序数组中的重复项（很简单，稳）
69、x的平方根（需要掌握二分法）
103、二叉树的锯齿形遍历（稳），两种方法：1、始终从左至右遍历，始终先插入左子树、然后右子树，在append每一层数组的时候控制锯齿形（但是这样slice的性能不佳）；2、始终从右至左遍历，在append的时候也始终从后插入，但是在append的时候根据层次控制先插入左子树还是右子树。
34、排序数组中查找元素的第一个和最后一个位置(很稳，每次在使用二分找到之后，前后遍历的时候一定要注意下表不要小于0或者大于len，导致数组取下表溢出的情况)
19、删除链表的倒数第N个节点（稳，需要特别注意啊，差点采坑了，如果倒数第N个节点是头节点，所以需要引入dummy节点）
236、二叉树的最近公共祖先（思路已经想好了，要相信自己啊，题中给了p和q均存在于二叉树之中）
114、二叉树展开为链表（要熟悉，和遍历很多是一个套路，slice可以解决queue和stack的场景）
14、最长公共前缀（比较稳，又来了，要注意数组下表溢出检查啊）
8、字符串转换整数（问题是要及时止损，不要等到计算完了再判定是否溢出，中间早就溢出了，计算过程就不可控了）
91、解码方法（dp的应用，需要根据前一位和前两位的情况，分别来判定和dp[i-1]以及dp[i-1]的关系，需理解）
300、最长上升子序列（要熟悉，
i:=1;i<len;i++, j:=0,j<i;j++ 从小于i的所有j中找最大的来赋予当前的i，然后再加1）
41、缺失的第一个整数（因为是O(n)的时间复杂度，所以覆盖原数组，所以nums[i]应该在nums[nums[i]-1]的位置上，所以如果不在，就和其交换，然后在第二次遍历，找出第一个nums[i]不等于i+1的）
1114、多协程按序打印（golang channel的使用）
50、Pow(x,n)(方法要熟悉，使用二分法,lgN的复杂度，递归)
64、最小路径和（最简单的动态规划，稳）
207、排课（检查有向图中是否存在环，构造入度数组和邻接矩阵，然后将入度为0的逐步放入）
230、二叉搜索树的第k小值（中序遍历的改进，很好的方法）


## 刷题专项(都需要突破啊)
76、最小覆盖子串（字节跳动面试有考到类似题，先找到counter==0的情况，然后再遍历left，检查是否可以缩小）
（如果是需要完全一样，可以尝试，当counter==0的时候，来判断子串的长度要等于它）
124、二叉树的最大路径和（这种方法必须要掌握了，dfs，对于每个节点上返回max(left, right)... 然后result返回max(left+right+...)，更新+返回的不一样方式）
48、90度旋转矩阵（直接赋值，保持行/列一方不变）
279、完全平方数（给定一个数，查看最少可以由多少个完全平方数组成）递归
670、交换一次，使得原来的数结果最大
74、搜索二维有序数组（行和列都有序），和右上角开始比较，稳
155、获取栈的最小值方法（两个slice：data，min）
232、用两个栈实现队列（掌握方法，可用c++写）
1015、计算能被k整除的最小的 连续由1组成的 十进制 的数的长度（暴力）
171、Excel中按规则的字符串所在的index（简单）
73、矩阵行列置0（简单）
54、矩阵的螺旋型打印（很巧妙的方法）
127、单词阶梯（beginword经过wordlist的转换（每次转变一个单词）到endword的最小步数）BFS，很巧妙的方法
130、包围区域（Surrounded Regions），将被'X'包围的'O'设置成'X'，方法很巧妙（从四周的'O'开始DFS，将不满足的）
149、判断在同一条直线的点的最多个数（时间换空间，根据行列式判断三点在一条直线上(x1,x2,x3...1,1,1))
150、逆波兰表示法，计算值（栈的应用）
91、解码数字的方法（还是一道好题，lastOne和lastTwo的判定）
116、补齐二叉树每个节点的右指针（层次遍历可解，更秒的是纯指针操作）
329、找到二维矩阵中最长的一条递增路径的长度（DFS，好题）
239、滑动窗口里的最大值（priority_queue的方法掌握，deque的太巧妙）
334、数组中是否存在长度大于等于3的递增子序列（m1,m2的方法太巧妙了）
324、重排数组，使得大小大小这样间隔(排序后，两个指针分别放在mid和right，然后交叠着重新放入数组，注意数组的深拷贝和浅拷贝，要使两个分开，得用copy(dst, src))


## 牛客
最长可整合子数组的长度（两种方法：（1）排序之后依次来看，另外一种，hashset保存去重，然后O(n^2)判断子数组最大值减最小值+1的结果等于元素个数，即是可整合元素）


## 字符串专题
3、最长无重复子串
5、最长回文子串
14、多个字符串最长公共前缀
115、S中不同子序列等于T的个数（dp，好题）
44、字符串匹配
10、字符串匹配（和44对比起来看）
344、反转字符串（很简单，就不说了）
424、替换k个字符，找出能使连续字符的最长子串长度(滑动窗口，很好的题)
lintcod 386、最长k个不同字符的最长子串长度（滑动窗口，好题）
916、Word Subsets单词子集（golang用法好题）
139、单词分割（是否可以分割）（一个单词是否可以被一个集合中的单词分割，好题）
140、单词分割II（分割的所有可能）（好题）