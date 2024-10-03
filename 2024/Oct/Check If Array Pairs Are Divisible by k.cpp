class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
           mp[(arr[i] % k + k) % k]++; 
        }
        for(int i = 0; i < n; ++i) {
            int num = (arr[i] % k + k) % k;
            int need = (k - num) % k;
            if(mp[num] == 0) continue;
            mp[num]--;
            if(mp.find(need) != mp.end() && mp[need] > 0) {
                mp[need]--;
            }
            else {
                return false;
            }
    }
    return true;
    }

};
