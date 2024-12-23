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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int answer = 0;
        while(q.size()) {
            int sz = q.size();
            vector<int> v;
            for(int i = 0; i < sz; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp-> val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            answer += countSwaps(v);
        }
        return answer;
    }

    int countSwaps(vector<int> &v) {
        int answer = 0;
        map<int, int> mp;
        vector<int> cp;
        cp = v;
        sort(cp.begin(), cp.end());
        int n = v.size();
        for(int i = 0; i < n; ++i) {
            mp[v[i]] = i;
        }
        for(int i = 0; i < n; ++i) {
            int curr = mp[cp[i]];
            if(curr != i) {
                answer++;
                mp[v[i]] = mp[cp[i]];
                swap(v[i], v[mp[cp[i]]]);
            } 
        }
        return answer;
    }
};
