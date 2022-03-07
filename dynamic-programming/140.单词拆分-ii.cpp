/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (48.02%)
 * Likes:    569
 * Dislikes: 0
 * Total Accepted:    62K
 * Total Submissions: 120.6K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
 * 返回所有这些可能的句子。
 * 
 * 注意：词典中的同一个单词可能在分段中被重复使用多次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * 输出:["cats and dog","cat sand dog"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * 输出:[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中所有字符串都 不同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // store the ans and wordset
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordset;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordset = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int index) {
        if(!ans.count(index)) {
            if(index == s.size()) {
                ans[index] = {""};
                return;
            }

            ans[index] = {};
            for(int i = index + 1; i <= s.size(); i++) {
                string word = s.substr(index, i -index);
                if(wordset.count(word)) { // if word exits
                    backtrack(s, i);
                    for(auto succ: ans[i]) {
                        ans[index].push_back(succ.empty() ? word: word + " " + succ);
                    }
                }
            }
        }
    }
};
// @lc code=end

