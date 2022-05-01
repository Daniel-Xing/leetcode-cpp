/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.21%)
 * Likes:    1980
 * Dislikes: 0
 * Total Accepted:    601.4K
 * Total Submissions: 765.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<bool> selected;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& path) {
        if(path.size() == nums.size()) {
            ans.push_back(path);
        }

        for(int i = 0; i < nums.size(); i ++) {
            if(selected[i]) continue;

            selected[i] = true;
            path.push_back(nums[i]);
            
            dfs(nums, path);

            selected[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        selected = vector<bool>(nums.size(), false);
        ans = vector<vector<int>>(0, vector<int>(0));
        vector<int> path(0);

        dfs(nums, path);

        return ans;
    }
};
// @lc code=end

