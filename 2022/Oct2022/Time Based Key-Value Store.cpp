class TimeMap {
public:
    unordered_map<string, vector<int>> mp;
    unordered_map<string, vector<string>> mp2;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
    mp[key].push_back(timestamp);
    mp2[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int tym = 0;
        auto idx = lower_bound(mp[key].begin(), mp[key].end(), timestamp) - mp[key].begin();
        if(mp[key].size()) {
            if(idx == mp[key].size() || mp[key][idx] > timestamp) idx--;
           if(idx >= 0) ans += mp2[key][idx];
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
