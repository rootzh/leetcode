/*************************************************************************
 @Author: cecilzhang
 @Created Time : 2020年08月06日 星期四 16时12分48秒
 @File Name: /data/cecilzhang//mine/lc/1367.cpp
 @Description:
 @Copyright (c) 2018, Tencent Inc. All rights reserved.
 ************************************************************************/
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        bool isSubPath(ListNode* head, TreeNode* root) {
            if (head == NULL) {
                return true;
            }
            if (root == NULL) {
                return false;
            }
            if (root->val == head->val) {
                return isSubPath(head->next, root->left) || isSubPath(head->next, root->right) || isSubPath(head, root->left) || isSubPath(head, root->right);
            } else {
                return isSubPath(head, root->left) || isSubPath(head, root->right);
            }
        }
        bool isPath(ListNode* list, TreeNode* tree) {
            if (head == NULL) {
                return true;
            }
            if (root == NULL) {
                return false;
            }
            if (list->val != tree->val) {
                return false;
            }
            return isPath(list->next, tree->left)||isPath(list->next, tree->left);
        }
};
