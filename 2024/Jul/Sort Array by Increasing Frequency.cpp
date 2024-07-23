class Solution {
public:
bool static compare(pair<int, int> &a, pair<int, int> &b) {
	if(a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}
    vector<int> frequencySort(vector<int>& nums) {
	    unordered_map<int, int> mp;
	    for(auto it : nums) mp[it]++;
	    vector<pair<int, int>> vp;
	    for(auto it : mp) vp.push_back({it.second, it.first});
	    sort(vp.begin(), vp.end(), compare);
	    vector<int> answer;
        for(auto it : vp) {
            int n = it.first;
            for(int j = 0; j < n; ++j) answer.push_back(it.second);
        }
        return answer;
    }
};
