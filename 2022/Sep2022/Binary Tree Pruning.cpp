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
    TreeNode* pruneTree(TreeNode* root) {
		Traverse(root);
		return root;
    }
    
    bool Traverse(TreeNode* &root) {
		if(root == NULL) return true;
	    bool f = Traverse(root->left);
	    bool s = Traverse(root->right);
	    if(root->left == NULL && root->right == NULL) {
			//cout << root->val << " " << f << " " << s << endl;
			if(root->val == 0) {
				root = NULL;
				return false;
				}
				return true;
			}
	    if(f == false && s == false && root->val == 0) {
			root = NULL;
			if(root->left) root->left = NULL;
			if(root->right) root->right = NULL;
			return false;
			}
			return true;
		}
};
