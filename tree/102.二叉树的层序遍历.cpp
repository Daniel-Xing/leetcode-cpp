/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.21%)
 * Likes:    1137
 * Dislikes: 0
 * Total Accepted:    447.7K
 * Total Submissions: 697K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层序遍历结果：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto levelOrder = vector<vector<int>>();
        if (root == nullptr) return levelOrder;

        queue<TreeNode*> q = queue<TreeNode*>();
        q.push(root);
        while(!q.empty()) {
            vector<int> order = vector<int>();
            int currentLevelSize = q.size();
            for (int i = 1; i <= currentLevelSize ; ++i) {
                auto node = q.front();
                q.pop();
                order.push_back(node -> val);
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }

            levelOrder.push_back(order);
        }
        
        return levelOrder;
    }
};
// @lc code=end

