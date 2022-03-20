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
    int getKElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int index1 = 0, index2 = 0;
        int m = nums1.size(), n = nums2.size();

        while(1) {
            if(index1 == m ) {
                return nums2[index2 + k -1];
            }
            if(index2 == n ) {
                return nums1[index1 + k -1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            int newIndex1 = min(index1 + k/2 -1, m -1);
            int newIndex2 = min(index2 + k/2 -1, n -1);
            if(nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m + n) % 2 == 0) {
            return (getKElement(nums1, nums2, (m + n)/2) + getKElement(nums1, nums2, (m + n)/2 + 1)) / 2.0;
        } else {
            return getKElement(nums1, nums2, (m + n + 1)/2);
        }
    }
};
// @lc code=end

