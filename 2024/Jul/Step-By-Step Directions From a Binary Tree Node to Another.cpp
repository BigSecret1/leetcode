
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
    string left, right;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        left = right = "";
        string empty = "";
        char ch = '$';
        bool ok = true;
        Traverse(root, startValue, empty, ch, left, ok);
        empty = "";
        ok = true;
        Traverse(root, destValue, empty, ch, right, ok);
        int cnt = 0;
        while(cnt < left.size() && cnt < right.size()) {
            if(left[cnt] == right[cnt]) cnt++; 
            else break;
        }
        string answer = "";
        for(int i = cnt; i < left.size(); ++i) answer += 'U';
        for(int j = cnt; j < right.size(); ++j) answer += right[j];
        return answer;
        
    }

    void Traverse(TreeNode* root, int target, string &str, char move, string &answer, bool &ok) {
        if(ok == false || root == NULL) return;
        if(move != '$') str += move;
        if(root -> val == target) {
            ok = false;
            answer = str;
            return;
        } 
        Traverse(root->left, target, str, 'L', answer, ok);
        Traverse(root->right, target, str, 'R', answer, ok);
        if(str.size()) str.pop_back();
    }
};




