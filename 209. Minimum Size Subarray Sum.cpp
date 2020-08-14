class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = INT_MAX;
        int n = nums.size();
    
        vector<int> arr(n+1, 0);
        for(int i = 1; i <= n; i++) {
            arr[i] = arr[i-1] + nums[i-1];
        }
        
        int i = 1, j = 1;
        while(i <= n && j <= n) {
            if(arr[j] - arr[i-1] >= s) {
                ret = min(ret, j-i+1);
                i++;
            }
            else {
                j++;
            }
        }
        
        if(ret == INT_MAX) return 0;
        return ret;
    }
};