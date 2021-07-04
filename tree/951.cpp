/*************************************************************************
  @Author: cecilzhang
  @Created Time : 2020年08月18日 星期二 19时52分47秒
  @File Name: /data/cecilzhang//mine/leetcode/tree/951.cpp
  @Description:
  @Copyright (c) 2018, Tencent Inc. All rights reserved.
 ************************************************************************/
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
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            return equi(root1, root2);
        }

        bool equi(TreeNode* node1, TreeNode* node2) {
            if (node1 == NULL && node2 == NULL) {
                return true;
            }
            if ((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL)) {
                return false;
            }
            if ((getVal(node1->left) == getVal(node2->left) && getVal(node1->right) == getVal(node2->right))) {
                return equi(node1->left, node2->left) && equi(node1->right, node2->right);
            }
            if (getVal(node1->left) == getVal(node2->right) && (getVal(node1->right) == getVal(node2->left))) {
                return equi(node1->left, node2->right) && equi(node1->right, node2->left);
            }
            return false;
        }

        int getVal(TreeNode* node) {
            if (node == NULL) {
                return -1;
            }
            return node->val;
        }
};
