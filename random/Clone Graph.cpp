
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
       if(node == NULL) return node;
       queue<Node*> q;
       q.push(node);
       unordered_map<Node*, bool> mark;
       unordered_map<Node*, Node*> clone;
       mark[node] = true;
       clone[node] = new Node(node->val);
       while(q.size()) {
        Node* current = q.front();
        q.pop();
        for(Node* node : current->neighbors) {
           if(mark.find(node) == mark.end()) {
           Node* newNode = new Node(node->val);
           if(clone.find(node) == clone.end()) clone[node] = new Node(node->val);
            q.push(node);
            mark[node] = true;
           }
           clone[current]->neighbors.push_back(clone[node]); 
        }
       }
      return clone[node]; 
    }
};


