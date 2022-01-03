/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (75.22%)
 * Likes:    733
 * Dislikes: 0
 * Total Accepted:    344.9K
 * Total Submissions: 458.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    void myPostorder(vector<int>& postorder, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        myPostorder(postorder, root -> left);
        myPostorder(postorder, root -> right);
        postorder.push_back(root -> val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        myPostorder(postorder, root);

        return postorder;
    }
};
// @lc code=end

