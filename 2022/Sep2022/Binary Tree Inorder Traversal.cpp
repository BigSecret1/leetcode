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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        IOT(root, v);
        return v;
    }
    void IOT(TreeNode* root, vector<int> &v) {
        if(root == NULL) return;
        IOT(root->left, v);
        v.push_back(root->val);
        IOT(root->right, v);
    }
};
