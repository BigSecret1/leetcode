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
	map<pair<int, int>, vector<int>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    Traverse(root, 0, 0);
    vector<vector<int>> ans;
    map<int, vector<int>> mp2;
    for(auto it : mp) {
		sort(it.second.begin(), it.second.end());
	    for(auto it2 : it.second) {
			mp2[it.first.first].push_back(it2);
			}
		}
		for(auto it : mp2) {
			ans.push_back(it.second);
			}
    //for(int i = 0; i < ans.size(); ++i) {
		//sort(ans[i].begin(), ans[i].end());
		//}
		return ans;
    }
    
    void Traverse(TreeNode* root, int i, int j) {
		if(root == NULL) return;
		mp[{j, i}].push_back(root->val);
		Traverse(root->left, i + 1, j - 1);
		Traverse(root->right, i + 1, j + 1);
		}
};




