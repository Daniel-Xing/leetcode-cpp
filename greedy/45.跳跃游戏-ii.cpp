/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (43.68%)
 * Likes:    1368
 * Dislikes: 0
 * Total Accepted:    250.3K
 * Total Submissions: 572.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int right_index = nums[0];
        int new_right = right_index;
        int n = nums.size();
        int step = 0;

        for (int i = 1; i < n ; i++) {
            for (int j = i; j < n && j <= right_index; j++) {
                if(j + nums[j] > new_right) new_right = j + nums[j];
            }
            i = right_index;
            right_index = new_right;
            step ++;
        }

        return step;
    }
};
// @lc code=end

