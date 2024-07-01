class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       int oddCount = 0;
       int n = arr.size();
       for(int i = 0; i < n; ++i) {
            if(arr[i] % 2) {
                oddCount++;
            }
            else {
                oddCount = 0;
            }
            if(oddCount == 3) return true;
       } 
       return false;
    }
};
