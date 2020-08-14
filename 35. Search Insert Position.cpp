class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator low = lower_bound(nums.begin(), nums.end(), target);
        if(low != nums.end()) {
            if(*low == target) {
                return (low - nums.begin());
            }
            else {
                return (low - nums.begin() + 1);
            }
        }
        return nums.size();
    }
};