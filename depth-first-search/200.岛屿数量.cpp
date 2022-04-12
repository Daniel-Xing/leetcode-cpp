/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (55.01%)
 * Likes:    1657
 * Dislikes: 0
 * Total Accepted:    446.1K
 * Total Submissions: 777K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int n, m;
    void distory_island(vector<vector<char>>& grid, int i, int j) {
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '0') return;

        grid[i][j] = '0';
        distory_island(grid, i + 1, j);
        distory_island(grid, i - 1, j);
        distory_island(grid, i, j + 1);
        distory_island(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(grid[i][j] == '1') {
                    distory_island(grid, i, j);
                    count ++;
                }
            }
        }

        return count;
    }
};
// @lc code=end

