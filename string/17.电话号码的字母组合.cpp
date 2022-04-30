/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.10%)
 * Likes:    1870
 * Dislikes: 0
 * Total Accepted:    473.7K
 * Total Submissions: 820.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    inline vector<char> getChars(char digit) {
        int number = digit == '9' or digit == '7' ? 4:3;
        vector<char> ans(number);
        
        for(int i = 0; i < number; i ++) {
            if(digit <= '7') ans[i] = (digit - 50)*3 + 97 + i;
            else ans[i] = (digit - 50)*3 + 98 + i;
        }

        return ans;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>(0);

        // build the map: digit -> ["char", "char", "char"]
        vector<vector<char>> digit_map(digits.size());
        int count = 1;
        for(int i = 0; i < digits.size(); i++) {
            digit_map[i] = getChars(digits[i]);
            count *= digit_map[i].size();
        }

        // create the ans vector
        vector<string> ans(count, digits);

        // loop to insert
        int step = 1;
        for(int i = 0 ; i < digit_map.size(); i ++) {
            for(int j = 0; j < count; j ++) {
                ans[j][i] = digit_map[i][j / step % digit_map[i].size()];
            }

            step *= digit_map[i].size();
        }

        return ans;
    }
};
// @lc code=end

