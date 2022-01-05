/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.29%)
 * Likes:    2259
 * Dislikes: 0
 * Total Accepted:    400.2K
 * Total Submissions: 517.8K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr) return cache[n];
        if (n == 0) {
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        }else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0 ; i< n ; i++) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left: *lefts) {
                    for (const string& right: *rights) {
                        result -> push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = result;
        }
        return cache[n];
    }

    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};
// @lc code=end

