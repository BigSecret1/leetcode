/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        vector<int> v;
        v.push_back(root->val);
        ans.push_back(v);
        q.push(root);
        while(q.size()) {
			int sz = q.size();
			v.clear();
			for(int j = 0; j < sz; ++j) {
			Node* temp = q.front();
			q.pop();
			for(auto it : temp->children) {
				v.push_back(it->val);
				q.push(it);
				}
		}
		if(v.size())ans.push_back(v);
			}
			return ans;
    }
};





