/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (73.68%)
 * Likes:    658
 * Dislikes: 0
 * Total Accepted:    247.9K
 * Total Submissions: 335.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(0);
        for(int i = 1; i <= numRows; i++) {
            vector<int> temp(0);
            for(int j = 0; j < i; j ++) {
                if(j == 0) temp.push_back(1);
                else if (j == i -1) temp.push_back(1);
                else {
                    // std::cout << i << std::endl;
                    temp.push_back(ans.back()[j-1] + ans.back()[j]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
// @lc code=end

