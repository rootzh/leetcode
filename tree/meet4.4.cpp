/*************************************************************************
  @Author: cecilzhang
  @Created Time : 2020年08月13日 星期四 19时52分12秒
  @File Name: /data/cecilzhang//mine/leetcode/tree/meet4.4.cpp
  @Description:
  @Copyright (c) 2018, Tencent Inc. All rights reserved.
 ************************************************************************/

struct CmpByKey{
    bool operator()(TreeNode* k1, TreeNode* k2) const {
        return k1<k2;
    }
};
class Solution {
    private:
        map<TreeNode*,int, CmpByKey> height;
    public:
        bool isBalanced(TreeNode* root) {
            if (root == NULL) {
                return true;
            }
            getAllHeight(root);
            queue<TreeNode*> list;
            list.push(root);
            while(!list.empty()) {
                TreeNode* node = list.front();
                list.pop();
                if (abs(getHeight(node->left) - getHeight(node->right)) > 1) {
                    return false;
                }
                if (node->left != NULL) {
                    list.push(node->left);
                }
                if (node->right != NULL) {
                    list.push(node->right);
                }
            }
            return true;
        }

        int getHeight(TreeNode* node) {
            if (node != NULL) {
                return height[node];
            }
            return 0;
        }

        int getAllHeight(TreeNode* node) {
            if (node == NULL) {
                return 0;
            }
            auto iter = height.find(node);
            if (iter != height.end()) {
                return iter->second;
            }

            height[node] = max(getAllHeight(node->left), getAllHeight(node->right)) + 1;
            return height[node];
        }

        int max(int a, int b) {
            if (a > b) {
                return a;
            }
            return b;
        }
};

