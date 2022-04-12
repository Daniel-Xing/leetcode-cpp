/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (48.12%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    55K
 * Total Submissions: 107.7K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 * 
 * 实现词典类 WordDictionary ：
 * 
 * 
 * WordDictionary() 初始化词典对象
 * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些
 * '.' ，每个 . 都可以表示任何一个字母。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 输出：
 * [null,null,null,null,false,true,true,true]
 * 
 * 解释：
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * addWord 中的 word 由小写英文字母组成
 * search 中的 word 由 '.' 或小写英文字母组成
 * 最多调用 50000 次 addWord 和 search
 * 
 * 
 */

// @lc code=start
struct TireTree {
    vector<TireTree*> child;
    bool isEnd;

    TireTree(){
        this -> child = vector<TireTree *>(26, nullptr);
        this -> isEnd = false;
    }
};

void insert(TireTree* root, const string & word) {
    TireTree* node = root;

    for(auto& v : word) {
        if(node -> child[v - 'a'] == nullptr) {
            node -> child[v - 'a'] = new TireTree();
        }

        node = node -> child[v - 'a'];
    }

    node -> isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        tire = new TireTree();
    }
    
    void addWord(string word) {
        insert(tire, word);
    }
    
    bool search(string word) {
        return dfs(word, 0, tire);
    }

    bool dfs(const string & word,int index,TireTree * node) {
　　　　if (index == word.size()) {
            return node->isEnd;    
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TireTree * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TireTree * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    TireTree* tire;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

