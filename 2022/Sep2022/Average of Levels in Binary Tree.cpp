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
	double v1[20];
	int cnt = 1;
    vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		queue<TreeNode*> q;
		q.push(root);
		while(q.size()) {
			int sz = q.size();
			double sum = 0;
			for(int i = 0; i < sz; ++i) {
				TreeNode *temp = q.front();
				q.pop();
				sum += temp->val;
				if(temp->left != NULL) q.push(temp->left);
				if(temp->right != NULL) q.push(temp->right);
				}
				ans.push_back(sum / sz);
			}
			return ans;
    }
    

};
