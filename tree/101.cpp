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
        bool isSymmetric(TreeNode* root) {
            if (root == NULL || ((root->left == NULL) && (root->right == NULL))) {
                return true;
            }
            vector<TreeNode*> list, tmpList;
            list.push_back(root);
            while (!list.empty()) {
                if (!symmetric(list) && list[0] != root) {
                    return false;
                }
                for (auto iter = list.begin(); iter < list.end(); ++iter) {
                    if ((*iter) == NULL) {
                        continue;
                    }
                    if ((*iter)->left != NULL) {
                        tmpList.push_back((*iter)->left);
                    } else {
                        tmpList.push_back(NULL);
                    }
                    if ((*iter)->right != NULL) {
                        tmpList.push_back((*iter)->right);
                    } else {
                        tmpList.push_back(NULL);
                    }
                }
                list.clear();
                list.swap(tmpList);
            }
            return true;
        }

        bool symmetric(vector<TreeNode*>& node) {
            if (node.size() %2 != 0) {
                return false;
            }
            int size = node.size() /2;
            for (int i = 0; i< size; ++i) {
                if ((node[size-i-1] == NULL) && (node[i+size] == NULL)) {
                    continue;
                }
                if (((node[size-i-1] != NULL) && (node[i+size] == NULL)) || (node[size-i-1] == NULL && node[i+size] != NULL)) {
                    return false;
                }
                if (node[size-i-1]->val != node[i+size]->val) {
                    return false;
                }
            }
            return true;
        }
};

