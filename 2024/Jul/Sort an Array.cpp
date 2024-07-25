class Solution {
private:

    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp(high - low + 1, 0);
        int idx  = 0;
        int lIdx = low;
        int rIdx = mid;
        while(lIdx < mid && rIdx <= high){
            if(nums[lIdx] <= nums[rIdx]){
                temp[idx++] = nums[lIdx++];
            }
            else{
                temp[idx++] = nums[rIdx++];
            }
        }
        while(lIdx < mid){
            temp[idx++] = nums[lIdx++];
        }
        while(rIdx <= high){
            temp[idx++] = nums[rIdx++]; 
        }
        idx = 0;
        for(int i = low ; i <= high ; i++){
            nums[i] = temp[idx++];
        }

    }
    
    void mergeSort(vector<int> &nums, int low, int high){
        if(low < high){
            int mid = low + (high - low) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid + 1, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int sz = nums.size();
        mergeSort(nums, 0, sz - 1);
        return nums;
    }
};
