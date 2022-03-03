/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (43.23%)
 * Likes:    1780
 * Dislikes: 0
 * Total Accepted:    217.8K
 * Total Submissions: 497.1K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        // build left index
        stack<int> mono_stack;
        for(int i =0; i< n; i++) {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }

            left[i] = (mono_stack.empty() ? -1:mono_stack.top());
            mono_stack.push(i);
        }

        // build right index
        mono_stack = stack<int>();
        for(int i = n-1; i >=0; i--) {
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }

            right[i] = (mono_stack.empty() ? n:mono_stack.top());
            mono_stack.push(i);
        }

        int area = 0;
        for(int i = 0 ; i < n; i++) {
            area = max(area, (right[i] - left[i] -1)*heights[i]);
        }

        return area;
    }
};
// @lc code=end

