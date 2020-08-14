class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        
        int low = 0; int high = nums.size() - 1;
        int mid = (low + high) / 2;
        
        bool flag = true;
        if(mid+1 < nums.size() && nums[mid] < nums[mid+1]) flag = false;
        if(mid-1 >= 0 && nums[mid] < nums[mid-1]) flag = false;
        
        if(flag) {
            return mid;
        }
        else {
            if(mid+1 < nums.size() && nums[mid] < nums[mid+1]) {
                vector<int> vec(nums.begin() + mid + 1, nums.end());
                return mid + 1 + findPeakElement(vec);
            }
            else {
                vector<int> vec(nums.begin(), nums.begin() + mid);
                return findPeakElement(vec);
            }
        }
        
        return -1;
    }
};