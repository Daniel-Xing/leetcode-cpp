/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (68.68%)
 * Likes:    630
 * Dislikes: 0
 * Total Accepted:    160.8K
 * Total Submissions: 234K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void MyPaths(TreeNode* root, vector<string>& res, string path) {
        if (root == nullptr) {
            return;
        }

        if (root -> left == nullptr && root -> right == nullptr) {
            res.push_back(path + to_string(root -> val));
            return;
        }

        MyPaths(root -> left, res, path + to_string(root -> val) + "->");
        MyPaths(root -> right, res, path + to_string(root -> val) + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        MyPaths(root, res, "");
        return res;
    }
};
// @lc code=end

