/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.64%)
 * Likes:    5172
 * Dislikes: 0
 * Total Accepted:    648.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        int left = 1, right = x/2;
        int ans = left;
        long mid;
        while (left <= right) {
            mid = (left + right) /2;
            if(mid*mid == x) {
                return mid;
            }else if(mid*mid < x) {
                left = mid + 1;
                ans = mid;
            }else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end

