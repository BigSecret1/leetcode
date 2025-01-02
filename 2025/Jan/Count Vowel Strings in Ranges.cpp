class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0), answer;
        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i];
            if(isVowString(words[i])) prefix[i + 1]++;
        }
        int m = queries.size();
        for(int j = 0; j < m; ++j) {
            int l = queries[j][0];
            int r = queries[j][1];
            answer.push_back(prefix[r + 1] - prefix[l]);
        }
        return answer;
    }

    bool isVowString(string str) {
        int n = str.size();
        return isVowel(str[0]) && isVowel(str[n - 1]);
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
