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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        map<int, int> mp;
        Solve(root, v);
        for(auto it : v) {
            if(mp[k - it]) return true;
            mp[it]++;
        }
        return false;
    }
    void Solve(TreeNode *root, vector<int> &v) {
        if(root == NULL) return;
        v.push_back(root->val);
        Solve(root->left, v);
        Solve(root->right, v);
    }
};
