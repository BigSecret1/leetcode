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
	vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> v;
        Traverse(root, targetSum, 0, v);
        return ans;
    }
    
    void Traverse(TreeNode* root, int targetSum, int sum, vector<int> &v) {
		if(root == NULL) {
			return;
			}
			v.push_back(root->val);
			sum += root->val;
			if(root->left == NULL && root->right == NULL) {
				if(sum == targetSum) ans.push_back(v);
				v.pop_back();
				return;
				}
			Traverse(root->left, targetSum, sum, v);
			Traverse(root->right, targetSum, sum, v);
			if(v.size()) v.pop_back();
		}
    
};












