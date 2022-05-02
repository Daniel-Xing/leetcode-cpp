/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.37%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    90.8K
 * Total Submissions: 110.3K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int col, int ld, int rd) {
        if (row == n) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int pos = 1 << i;
            if ((col & pos) || (ld & pos) || (rd & pos)) {
                continue;
            }
            res += solve(n, row + 1, col | pos, (ld | pos) << 1, (rd | pos) >> 1);
        }
        return res;
    }
};
// @lc code=end

