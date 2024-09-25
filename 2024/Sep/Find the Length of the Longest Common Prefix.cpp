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
