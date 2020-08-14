class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        int sum = 0;
        int ret = 0;
        m[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            m[sum]++;
            ret += m[sum - k];
            if(k == 0) ret -= 1;
        }
        
        return ret;
    }
};