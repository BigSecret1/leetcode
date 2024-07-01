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
	int ans = 0;
    int goodNodes(TreeNode* root) {
        Traverse(root, INT_MIN);
        return ans;
    }
    
    void Traverse(TreeNode* root, int mx) {
		if(root == NULL) return;
		if(root->val >= mx) {
			ans++;
			mx = max(mx, root->val);
			}
			Traverse(root->left, mx);
			Traverse(root->right, mx);
		}
};
