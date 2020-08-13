/*************************************************************************
 @Author: cecilzhang
 @Created Time : 2020年08月13日 星期四 19时18分06秒
 @File Name: /data/cecilzhang//mine/lc/173.cpp
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
class BSTIterator {
    private:
        vector<int> values;
        int cur;
    public:
        BSTIterator(TreeNode* root):cur(0) {
            initValues(root);
            return;
        }

        void initValues(TreeNode* root) {
            if (root == NULL) {
                return;
            }
            initValues(root->left);
            values.push_back(root->val);
            initValues(root->right);
            return;
        }

        /** @return the next smallest number */
        int next() {
            return values[cur++];
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            if (cur >= values.size()) {
                return false;
            }
            return true;
        }
};

/**
 *  * Your BSTIterator object will be instantiated and called as such:
 *   * BSTIterator* obj = new BSTIterator(root);
 *    * int param_1 = obj->next();
 *     * bool param_2 = obj->hasNext();
 *      */
