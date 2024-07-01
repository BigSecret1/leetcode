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
    
    string tree2str(TreeNode* root) {
        string ans = Traverse(root);
        return ans;
    }
    
    string Traverse(TreeNode* root) {
        if(root == NULL) return "";
        if(root->left == NULL && root->right == NULL) {
            int x = root->val;
            x = abs(x);
            string c = to_string(x);
            string ans = "";
            ans += c;
            if(root->val < 0) ans = "-" + ans;
            return ans;
        }
        string f = Traverse(root->left);
        string s = Traverse(root->right);
        if(f == "" && s != "") f = "()";
        int x = root->val;
        x = abs(x);
        string c = to_string(x);
        string ans = "";
        ans += (f == "()" ? f + "" : "(" + f + ")");
        if(s != "") ans += ("(" + s + ")");
        ans = c + ans;
        if(root->val < 0) ans = "-" + ans;
        return ans;
    }
};


















