/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.17%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    191.7K
 * Total Submissions: 335.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder = vector<vector<int>>();
        if (root == nullptr) return levelOrder;

        auto q = queue<TreeNode*>();
        q.push(root);
        bool isOrderLeft = true;

        while(!q.empty()){
            auto levelList = deque<int>();
            int size = q.size();
            for (int i = 0; i < size ; ++i) {
                auto node = q.front();
                q.pop();
                if (isOrderLeft) {
                    levelList.push_back(node -> val);
                }else {
                    levelList.push_front(node -> val);
                }

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }

            levelOrder.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return levelOrder;
    }
};
// @lc code=end

