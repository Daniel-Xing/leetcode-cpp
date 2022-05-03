/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (45.73%)
 * Likes:    651
 * Dislikes: 0
 * Total Accepted:    74K
 * Total Submissions: 162K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
 * 
 * 单词必须按照字母顺序，通过 相邻的单元格
 * 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * 输出：["eat","oath"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] 是一个小写英文字母
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] 由小写英文字母组成
 * words 中的所有字符串互不相同
 * 
 * 
 */

// @lc code=start
struct Tire {
    string word;
    unordered_map<char, Tire*> children;
    
    Tire() {
        this -> word = "";
    }
};

void insertWord(string& word, Tire* root) {
    auto curr = root;

    for(auto w: word) {
        if(!curr -> children.count(w)) {
            curr -> children[w] = new Tire();
        }
        curr = curr -> children[w];
    }

    curr -> word = word;
}

class Solution {
public:
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, Tire* root, int i, int j, vector<string>& ans) {
        char ch = board[i][j];
        // cout << "index: " << i << " " << j << " ch:" << ch << endl;

        if(root == nullptr || !root -> children.count(ch)) return;

        // cout << "2index: " << i << " " << j << " ch:" << ch << endl;

        Tire* next = root -> children[ch];
        if(next -> word != "") {
            ans.push_back(next -> word);
            next -> word = "";
        }

        if(!next -> children.empty()) {
            board[i][j] = '*';
            for(int d = 0; d < 4; d++) {
                int next_i = i + dir[d][0];
                int next_j = j + dir[d][1];

                if(next_i >= 0 && next_i < board.size() && next_j >= 0 && next_j < board[0].size()) {
                    if (board[next_i][next_j] != '*' ) {
                        // cout << i << " " << j << " -> " << next_i << " " << next_j << endl;
                        dfs(board, next, next_i, next_j, ans);
                        }
                }
            }
            board[i][j] = ch;
        }

        if(next -> children.empty()) {
            root -> children.erase(ch);
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans(0);

        Tire* root = new Tire();
        for(auto w: words) {
            insertWord(w, root);
        }

        for(int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[0].size(); j ++) {
                dfs(board, root, i, j, ans);
            }
        }

        return ans;
    }
};
// @lc code=end

