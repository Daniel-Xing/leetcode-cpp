/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (47.11%)
 * Likes:    846
 * Dislikes: 0
 * Total Accepted:    129.2K
 * Total Submissions: 274K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         vector<int> dp(matrix[0].size(), 0);

         int pre;
         int max_len = 0;
         for(int i = 0; i < matrix.size(); i++) {
             for(int j = 0; j < matrix[0].size(); j ++) {
                if(i == 0) {
                    pre = dp[j];
                    dp[j] = matrix[i][j] - '0';
                } else if(j == 0) {
                    pre = dp[j];
                    dp[j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '0'){
                    pre = dp[j];
                    dp[j] = 0;
                } else{
                    int temp = dp[j];
                    dp[j] = min(pre, min(dp[j], dp[j-1])) + 1;
                    pre = temp;     
                }

                if(dp[j] > max_len) {
                    max_len = dp[j];
                }
             }
         }

         return max_len*max_len;
    }
};
// @lc code=end

