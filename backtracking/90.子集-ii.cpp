/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.45%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    196.7K
 * Total Submissions: 309.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        freq = vector<pair<int, int>>(0, pair<int, int>());
        ans = vector<vector<int>>(0, vector<int>());
        auto path = vector<int>(0);

        sort(nums.begin(), nums.end());
        for(auto v: nums) {
            if(freq.empty() || freq.back().first != v) {
                freq.push_back(pair<int, int>(v, 1));
            } else {
                freq.back().second ++;
            }
        }

        dfs(path, 0);
        return ans;
    }

    void dfs(vector<int>& path, int pos) {
        if(pos == freq.size()) {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < freq[pos].second; i ++) {
            path.push_back(freq[pos].first);
            dfs(path, pos + 1);
        }

        for(int i = 0; i < freq[pos].second; i ++) {
            path.pop_back();
        }

        dfs(path, pos + 1);

    }
};
// @lc code=end

