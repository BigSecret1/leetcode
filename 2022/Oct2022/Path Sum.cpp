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
    bool hasPathSum(TreeNode* root, int targetSum) {
    return Solve(root, targetSum, 0);
    }
    bool Solve(TreeNode* root, int target, int sum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) {
            if(sum + root->val == target) return true;
            else return false;
        }
        bool f = Solve(root->left, target, sum + root->val);
        bool s = Solve(root->right, target, sum + root->val);
        if(f || s) return true;
        else return false;
    }
};
