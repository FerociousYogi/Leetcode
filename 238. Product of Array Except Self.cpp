class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        
        int prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            ret.push_back(prod);
            prod *= nums[i];
        }
        
        prod = 1;
        for(int i = nums.size() - 1; i > 0; i--) {
            prod *= nums[i];
            ret[i-1] *= prod;
        }
        
        return ret;
    }
};