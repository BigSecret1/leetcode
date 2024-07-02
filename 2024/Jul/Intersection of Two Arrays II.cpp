
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	    int mx = 1005;
	    int arr1[mx], arr2[mx];
	    memset(arr1, 0, sizeof(arr1));
	    memset(arr2, 0, sizeof(arr2));
	    int n = nums1.size(), m = nums2.size();
	    for(int i = 0; i < n; ++i) {
		    int number = nums1[i];
		    arr1[number]++;
	    }
	    for(int j = 0; j < m; ++j) {
		    int number = nums2[j];
		    arr2[number]++;
	    }
	    vector<int> answer;
	    for(int i = 0; i < n; ++i) {
		    int number = nums1[i];
		    int mn = 0;
		    mn = min(arr1[number], arr2[number]);
		    if(mn) {
			    for(int j = 0; j < mn; ++j) answer.push_back(number);
			    arr1[number] = 0;
		    }
	    }
	    return answer;
    }
};
