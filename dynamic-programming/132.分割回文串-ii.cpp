/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (49.29%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 111.7K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
 * 
 * 返回符合要求的 最少分割次数 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：1
 * 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab"
 * 输出：1
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
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n == 1) return 0;
        
        // build helper 
        vector<vector<bool>> is_palin(n, vector<bool>(n, true));
        for(int l = 2; l <= n; l ++) {
            for(int i = 0; i < n; i++) {
                int j = i + l -1;
                if (j >= n) break;
                
                is_palin[i][j] = l == 2? s[i] == s[j]: s[i] == s[j] && is_palin[i+1][j-1];
            }
        }

        // update dp
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        f[1] = s[0] == s[1] ? 0:1;

        for(int i = 2; i < n; i ++) {
            for(int j = i -1; j >=0; --j) {
                if (is_palin[j+1][i]) f[i] = min(f[i], f[j] + 1);
            }
            if(is_palin[0][i]) f[i] = 0;
        }

        return f[n-1];
    }
};
// @lc code=end

