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
    int pseudoPalindromicPaths (TreeNode* root) {
		vector<int> v(10, 0);
    Traverse(root, v);
    return ans;
    }
    
    void Traverse(TreeNode* root, vector<int> cnt) {
		if(root == NULL) {
			return;
			}
		cnt[root->val]++;
		if(root->left == NULL && root->right == NULL) {
			int cntOdd = 0;
			for(auto it : cnt) if(it & 1) cntOdd++;
			if(cntOdd <= 1) ans++;
			return;
			}
		Traverse(root->left, cnt);
		Traverse(root->right, cnt);
	}
};
