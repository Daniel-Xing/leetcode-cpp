/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (72.41%)
 * Likes:    1016
 * Dislikes: 0
 * Total Accepted:    166.1K
 * Total Submissions: 228.7K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

    void dfs(const string& s, int index) {
        if(index == n) {
            ret.push_back(ans);
            return;
        }

        for(int i = index; i < n; i ++) {
            if(f[index][i]) {
                ans.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for(int i = n -1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};
// @lc code=end

