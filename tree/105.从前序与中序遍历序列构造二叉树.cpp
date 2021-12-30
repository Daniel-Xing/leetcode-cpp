/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.26%)
 * Likes:    1360
 * Dislikes: 0
 * Total Accepted:    280.3K
 * Total Submissions: 396.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * inorder.length == preorder.length
 * -3000 
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
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
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;

        root -> left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root -1);
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n ; i++) {
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};
// @lc code=end

