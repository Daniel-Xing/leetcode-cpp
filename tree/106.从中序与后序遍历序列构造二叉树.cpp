/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.09%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    150.6K
 * Total Submissions: 208.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    unordered_map<int, int> index;
public:

    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right) {
            return nullptr;
        }

        // std::cout << inorder_left << inorder_right << postorder_left << postorder_right << std::endl;
        int postorder_root = postorder_right;
        int inorder_root = index[postorder[postorder_root]];
        int size = inorder_root - inorder_left;
        // std::cout <<postorder[postorder_root] << " " << inorder_root << " size:"<< size << std::endl;
        TreeNode* root = new TreeNode(postorder[postorder_root]);

        root -> left = myBuildTree(inorder, postorder, inorder_left, inorder_root -1, postorder_left, postorder_left + size -1);
        root -> right = myBuildTree(inorder, postorder, inorder_left + size + 1, inorder_right, postorder_left + size, postorder_right -1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        
        for (int i = 0 ; i < size ; i ++) {
            index[inorder[i]] = i;
        }

        return myBuildTree(inorder, postorder, 0, size -1, 0, size -1);
    }
};
// @lc code=end

