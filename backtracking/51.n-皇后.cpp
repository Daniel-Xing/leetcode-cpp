/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.01%)
 * Likes:    1308
 * Dislikes: 0
 * Total Accepted:    210K
 * Total Submissions: 283.8K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
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
    vector<vector<string>> solveNQueens(int n) {
       auto solutions = vector<vector<string>>();
       auto queens = vector<int>(n, -1);
       solve(solutions, queens, n, 0, 0, 0, 0);

       return solutions;
    }

    void solve(vector<vector<string>>& solutions, vector<int>& queens, int n, 
                        int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int pos = availablePositions & (-availablePositions);
                availablePositions &= availablePositions - 1;
                int column = __builtin_ctz(pos);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, (columns | pos), (diagonals1 | pos) >> 1, (diagonals2 | pos) << 1);
                queens[row] = -1;                
            }
        }                        
                        
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
// @lc code=end

