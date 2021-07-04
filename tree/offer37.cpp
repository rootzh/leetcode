/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<iostream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) {
            return "[]";
        }
        queue<TreeNode*> list;
        list.push(root);
        while(!list.empty()){
            TreeNode* node = list.front();
            list.pop();
            if (node != NULL ) {
                res.append(",");
                res.append(to_string(node->val));
                list.push(node->left);
                list.push(node->right);
            } else {
                res.append(",null");
            }
        }
        res[0] = '[';
        res.append("]");
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 2) {
            return NULL;
        }
        vector<string> arr = getList(data);
        TreeNode* root = new TreeNode(stoi(arr[0]));
        int cur = 1;
        queue<TreeNode*> list;
        list.push(root);
        TreeNode* node;
        TreeNode* curNode;
        while (!list.empty()) {
            if (cur >= arr.size()) {
                break;
            }
            node = list.front();
            list.pop();
            for (int i = 0; i<2; ++i) {
                curNode = getnode(arr[cur+i]);
                if (curNode != NULL) {
                    list.push(curNode);
                }
                if (i == 0) {
                    node->left = curNode;
                } else {
                    node->right = curNode;
                }
            }
            cur += 2;
        }
        return root;
    }
    TreeNode* getnode(string data) {
        if (data == "null") {
            return NULL;
        }
        return new TreeNode(stoi(data));
    }

    vector<string> getList(string data) {
        int begin = 1;
        vector<string> res;
        for (int i = 1; i<data.size(); ++i){
            if (data[i] == ',' || data[i] == ']') {
                res.push_back(data.substr(begin, i-begin));
                begin = i + 1;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
