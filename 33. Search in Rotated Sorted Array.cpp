class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        int low = 0; int high = nums.size() - 1;
        int mid;
        
        while(low <= high) {
            mid = (low + high) / 2;
            
            if(nums[mid] == target) return mid;
            else {
                // left half is sorted
                if(nums[low] <= nums[mid]) {
                    if(nums[low] <= target && nums[mid] > target) high = mid - 1; 
                    else low = mid + 1;
                } 
                // right half is sorted
                else {
                    if(nums[high] >= target && nums[mid] < target) low = mid + 1;
                    else high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};