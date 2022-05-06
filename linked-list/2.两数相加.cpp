/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.65%)
 * Likes:    8036
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // prefer to use l1 to store the link
    // end condition ret == 0 and dfs -> l1.end
    // 1. l1 not null and l2 not null, add l2 to l1 plus rest
    // 2. l1 is null and l2 not null, transfer the rest nodes of l2 to l1
    // 3. l1 not null and l2 is null, add rest to the l1
    // 4. l1 is null and l2 is null, create the tail node or not based on rest 
    void dfs(ListNode* l1, ListNode* l2, int rest) {
        if(l1 == nullptr && l1 == nullptr && rest == 0) {
            return;
        }

        if(l1 != nullptr && l2 != nullptr && l1 -> next == nullptr && l2 -> next != nullptr) {
            l1 -> next = l2 -> next;
            l2 -> next = nullptr;
        }

        int result = rest;
        if(l1 != nullptr) result += l1 -> val;
        if(l2 != nullptr) result += l2 -> val;

        rest = result / 10;
        if(l1 != nullptr) l1 -> val = result % 10;
        if(l1 -> next == nullptr && rest != 0) l1 -> next = new ListNode();

        if(l1 != nullptr) l1 = l1 -> next;
        if(l2 != nullptr) l2 = l2 -> next;
        dfs(l1, l2 , rest);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = l1;
        dfs(l1, l2, 0);

        return head;
    }
};
// @lc code=end

