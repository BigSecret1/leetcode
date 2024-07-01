// I solved this problem using Kleene's algorithm 

class MyCalendarThree {
public:
    vector<pair<int, bool>> vp;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        vp.push_back({start, true});
        vp.push_back({end, false});
        sort(vp.begin(), vp.end());
        int cnt = 0;
        int ans = 1;
        for(auto it : vp) {
            if(it.second == true) cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
