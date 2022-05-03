/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (56.13%)
 * Likes:    894
 * Dislikes: 0
 * Total Accepted:    219.8K
 * Total Submissions: 391.5K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;

    vector<string> restoreIpAddresses(string s) {
        ans = vector<string>(0);
        string path = "";

        dfs(path, 0, s, 0);
        return ans;
    }

    void dfs(string path, int pos, string& s, int count) {
        if (count == 4) {
            if(pos == s.size()) ans.push_back(path.substr(0, path.size() -1));
            
            return;
        }

        if (pos >= s.size()) return;

        // 
        int dit_1 = stoi(s.substr(pos, 1));
        if(dit_1 >=0 && dit_1 <= 9) {
            dfs(path + s.substr(pos, 1) + ".", pos + 1, s, count + 1);
        }

        int dit_2 = stoi(s.substr(pos, 2));
        if(dit_2 >= 10 && dit_2 <= 99) {
            dfs(path + s.substr(pos, 2) + ".", pos + 2, s, count + 1);
        }

        int dit_3 = stoi(s.substr(pos, 3));
        if(dit_3 >= 100 && dit_3 <= 255) {
            dfs(path + s.substr(pos, 3) + ".", pos + 3, s, count + 1);
        }
     }
};
// @lc code=end

