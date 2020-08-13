/*************************************************************************
 @Author: cecilzhang
 @Created Time : 2020年08月10日 星期一 16时43分33秒
 @File Name: /data/cecilzhang//mine/lc/102.cpp
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            vector<TreeNode*> level;
            level.push_back(root);
            while (!level.empty()) {
                vector<int> tmp;
                vector<TreeNode*> levelTmp;
                for (auto iter = level.begin(); iter != level.end(); level++) {
                    tmp.push_back(iter->val);
                    if (iter->left != NULL) {
                        levelTmp.push_back(iter);
                    }
                    if (iter->right!= NULL) {
                        levelTmp.push_back(iter->right);
                    }
                }
                level.swap(levelTmp);
                res.push_back(tmp);
            }
            return res;
        }
};
