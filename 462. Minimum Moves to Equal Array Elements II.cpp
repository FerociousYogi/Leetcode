class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median;
        sort(nums.begin(), nums.end());
        if(n % 2 == 1) {
            median = nums[n/2];
        }
        else {
            median = nums[n/2] + nums[n/2 - 1];
            median /= 2;
        }
        
        int ret = 0;
        for(auto x : nums) {
            ret += abs(x - median);
        }
        
        return ret;
    }
};