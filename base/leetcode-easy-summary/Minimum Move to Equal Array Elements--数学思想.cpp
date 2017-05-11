
/* 
 *leetcode: 453
 *一次将n-1个元素加1，等价于把剩下那个元素减1
 */

int minMoves(vector<int>& nums) {
       return accumulate(nums.begin(), nums.end(), 0L)-nums.size()* *min_element(nums.begin(), nums.end());
}