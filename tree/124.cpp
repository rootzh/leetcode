/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
        int sum;
public:
    int maxPathSum(TreeNode* root){
        sum = root->val;
        maxSum(root);
        return sum;
    }

    int maxSum(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int left = max(maxSum(node->left),0);
        int right = max(maxSum(node->right),0);
        int curVal = left + right + node->val;
        if (sum < curVal) {
            sum = curVal;
        }
        return max(left, right) + node->val;
    }

    int max(int a, int b) {
        return a>b?a:b;
    }
};

