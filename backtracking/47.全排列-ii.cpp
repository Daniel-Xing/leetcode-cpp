/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (63.58%)
 * Likes:    1045
 * Dislikes: 0
 * Total Accepted:    309.2K
 * Total Submissions: 478.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<pair<int, int>> freq;
    int ans_length;

    void dfs(vector<int>& path) {
        if(path.size() == ans_length) {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < freq.size(); i ++) {
            if(freq[i].second == 0) continue;

            path.push_back(freq[i].first);
            freq[i].second --;
            dfs(path);

            path.pop_back();
            freq[i].second ++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans = vector<vector<int>>(0, vector<int>(0));
        
        sort(nums.begin(), nums.end());
        for(auto v: nums) {
            if(freq.empty() || v != freq.back().first) {
                freq.emplace_back(v, 1);
            } else {
                freq.back().second ++;
            }
        }

        ans_length = nums.size();

        vector<int> path(0);
        dfs(path);

        return ans;
    }
};
// @lc code=end

