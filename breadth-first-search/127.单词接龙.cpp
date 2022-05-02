/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (47.49%)
 * Likes:    1021
 * Dislikes: 0
 * Total Accepted:    146.8K
 * Total Submissions: 309.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 ->
 * s2 -> ... -> sk：
 * 
 * 
 * 每一对相邻的单词只差一个字母。
 * 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
 * sk == endWord
 * 
 * 
 * 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列
 * 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：5
 * 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：0
 * 解释：endWord "cog" 不在字典中，所以无法进行转换。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有字符串 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> wordDic;
    vector<vector<int>> edges;
    int nodeNum = 0;

    void addWord(string& word) {
        if(!wordDic.count(word)) {
            wordDic[word] = nodeNum ++;
            edges.emplace_back();
        }
    }

    void addEdges(string& word) {
        addWord(word);
        int id1 = wordDic[word];
        for(char& w: word) {
            char tmp = w;
            w = '*';
            addWord(word);
            int id2 = wordDic[word];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            w = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addEdges(beginWord);
        for(auto word: wordList) {
            addEdges(word);
        }

        if(!wordDic[endWord]) {
            return 0;
        }
        

        vector<int> dis(edges.size(), INT_MAX);
        int beginId = wordDic[beginWord], endId = wordDic[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while(!que.empty()){
            auto front = que.front();
            que.pop();

            if(front == endId) {
                return dis[endId] / 2 + 1;
            }

            for(auto& e: edges[front]) {
                if(dis[e] == INT_MAX) {
                    dis[e] = dis[front] + 1;
                    que.push(e);
                }
            }
        }

        return 0;
    }
};
// @lc code=end

