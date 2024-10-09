class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string a, b;
        a = sentence1;
        b = sentence2;
        vector<string> va, vb;
        pushWords(va, a);
        pushWords(vb, b);
        int n = va.size();
        int m = vb.size();
        if(n > m) swap(n, m), swap(va, vb);
        deque<string> dq;
        for(auto it : va) dq.push_back(it);
        for(int j = 0; dq.size() && j < m; ++j)  {
            if(vb[j] == dq.front()) {
                dq.pop_front();
            }
            else break;
        }
        for(int j = m - 1; dq.size() && j >= 0; --j) {
            if(vb[j] == dq.back()) {
                dq.pop_back();
            }
            else break;
        }
        if(dq.size()) return false;
        return true;
    }

    void pushWords(vector<string> &a, string str) {
        string temp = "";
        for(auto it : str) {
            if(it == ' ') {
                a.push_back(temp);
                temp = "";
            }
            else temp += it;
        }
        if(temp.size()) a.push_back(temp);
    }
};
