/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (51.65%)
 * Likes:    1187
 * Dislikes: 0
 * Total Accepted:    115.1K
 * Total Submissions: 220.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：6
 * 解释：最大矩形如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：matrix = [["1"]]
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：matrix = [["0","0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == matrix.length
 * cols == matrix[0].length
 * 1 <= row, cols <= 200
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j-1]) + 1;
                }
            }
        }

        // calculate
        int res = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;

                int width = left[i][j];
                int area = width;
                for(int k = i -1; k >=0; k --) {
                    width = min(width, left[k][j]);
                    area = max(area, (i-k+1)*width);
                }

                res = max(res, area);
            }
        }

        return res;
    }
};
// @lc code=end

