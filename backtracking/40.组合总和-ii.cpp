/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (63.00%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    187.1K
 * Total Submissions: 297.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int target, int idx) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }

        if(idx == freq.size() || target < freq[idx].first) {
            return;
        }

        dfs(target, idx + 1);

        int most = min(target/ freq[idx].first, freq[idx].second);
        for(int i = 1; i <= most; i++) {
            path.push_back(freq[idx].first);
            dfs(target - freq[idx].first * i, idx + 1);
        }

        for(int i = 1; i <= most; i ++) {
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(auto v: candidates) {
            if(freq.empty() || v != freq.back().first) {
                freq.emplace_back(v, 1);
            }else {
                freq.back().second ++;
            }
        }

        dfs(target, 0);
        return ans;
    }
};
// @lc code=end

