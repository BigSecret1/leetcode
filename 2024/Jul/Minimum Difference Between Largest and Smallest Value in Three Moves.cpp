class Solution {
public:
    int minDifference(vector<int>& nums) {
	    int n = nums.size();
	    if(n <= 3) return 0;
	    sort(nums.begin(), nums.end());
	    long long l = 0; 
	    long long r= nums[n - 1];
	     long long answer = l;
	    if(n <= 3) return 0;
	    long long last = nums[n - 1];
	    int first = nums[0];
	    answer = last - first;
	    for(int i = -1; i < 3; ++i) {
		     long long front = nums[i + 1];
		     long long back = nums[n - 1 - (3 - i - 1)];
		     answer = min(answer, back - front);
	    }
		    return answer;
    }

};
