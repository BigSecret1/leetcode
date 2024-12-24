class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combo;
        getCombo(candidates, 0, target, 0, combo, answer);
        return answer;
    }

    void getCombo(vector<int> v, int idx, int target, int sum, vector<int> &combo, vector<vector<int>> &answer) {
        if(sum == target) {
            answer.push_back(combo);
            return;
        }
        if(sum > target || idx >= v.size()) return;
        combo.push_back(v[idx]);
        getCombo(v, idx, target, sum + v[idx], combo, answer);
        combo.pop_back();
        getCombo(v, idx + 1, target, sum, combo, answer);
    }
};
