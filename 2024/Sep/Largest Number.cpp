class Solution {
public:

    static bool cmp(string a, string b) {
        return (a + b) > (b + a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto it : nums) {
            str.push_back(to_string(it));
        }
        sort(str.begin(), str.end(), cmp);
        string answer = "";
        for(auto it : str) answer += it;
        if(answer[0] == '0') answer = '0';
        return answer;
    }
};
