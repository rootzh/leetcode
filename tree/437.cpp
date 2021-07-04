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
private:
    int num;
public:
    Solution():num(0){}
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        getNum(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return num;
    }

    void getNum(TreeNode* node, int sum) {
        if (node == NULL) {
            return;
        }
        if (sum - node->val == 0) {
            ++num;
        }
        getNum(node->left, sum - node->val);
        getNum(node->right, sum - node->val);
        return;
    }
};

