class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, bool> mp;
        int n = arr1.size();
        for(int i = 0; i < n; ++i) {
            string str = to_string(arr1[i]);
            string newStr = "";
            for(char ch : str) {
                newStr += ch;
                mp[newStr] = true;
            }
        }
        int answer = 0;
        n = arr2.size();
        for(int i = 0; i < n; ++i) {
            string str = to_string(arr2[i]);
            string newStr = "";
            for(char ch : str) {
                newStr += ch;
                if(mp.find(newStr) != mp.end()) {
                    int prefixLen = newStr.size();
                    answer = max(answer, prefixLen);
                }
            }
        }
        return answer;
    }
};


class TrieNode {
public:

    TrieNode* children[10];

    TrieNode() {
        for(int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    
    TrieNode* root;

    Trie() {root = new TrieNode();}

    void insert(int num) {
        TrieNode *node = root;
        string numStr = to_string(num);
        for(char ch : numStr) {
            int idx = ch - '0';
            if(!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int search(int num) {
        TrieNode *node = root;
        int len = 0;
        string numStr = to_string(num);
        for(char ch : numStr) {
            int idx = ch - '0';
            if(node->children[idx]) {
                len++;
                node = node->children[idx];
            }
            else {
                break;
            }
        }
        return len;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie; 
        for(auto it : arr1) trie.insert(it);
        int answer = 0;
        for(auto it : arr2) {
            int len = trie.search(it);
            answer = max(answer, len);
        }
        return answer;
    }
}
