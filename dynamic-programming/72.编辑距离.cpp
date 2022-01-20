/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (61.60%)
 * Likes:    2055
 * Dislikes: 0
 * Total Accepted:    203.2K
 * Total Submissions: 329.8K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * word1 和 word2 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_length = word1.size();
        int word2_length = word2.size();

        std::vector<int> dp(word1_length + 1);
        int pre;
        for(int i = 0; i <= word2_length ; i ++) {
            for(int j = 0; j <= word1_length; j ++) {
                if (i == 0) {
                    dp[j] = j;
                    continue;
                }
                if (j == 0) {
                    dp[0] = i;
                    pre = i -1;
                    continue;
                }

                // if (i == 1 && j == 1 && word1[j-1] == word2[i-1]) std::cout << "ok" <<std::endl;

                if (word1[j-1] == word2[i-1]) {
                    int temp = dp[j];
                    dp[j] = min(min(dp[j], dp[j-1]) +1, pre);
                    pre = temp;
                }else {
                    int temp = dp[j];
                    dp[j] = min(min(dp[j], dp[j-1]), pre) +1;
                    pre = temp;
                }
            }

            // for(int j = 0; j <= word1_length; j ++) {
            //     std::cout << dp[j] << " ";
            // }

            // std::cout << endl;
        }

        return dp[word1_length];
    }
};
// @lc code=end

