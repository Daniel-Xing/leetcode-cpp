/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (77.04%)
 * Likes:    964
 * Dislikes: 0
 * Total Accepted:    340.1K
 * Total Submissions: 441.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        auto ans = vector<vector<int>>(0, vector<int>(0));
        auto path = vector<int>(0);

        dfs(ans, path, n, k, 1);
        return ans;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, int n, int k, int start) {
        // if(n - start + 1 < k) return;

        if(path.size() == k) {
            res.push_back(path);
            return;
        }   

        for(int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(res, path, n, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

