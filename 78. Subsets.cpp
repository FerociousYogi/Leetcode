class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        int n = nums.size();
        
        for(int i = 0; i < pow(2, n); i++) {
            vector<int> tobepushed;
            for(int j = 0; j < 32; j++) {
                if(1 << j & i) tobepushed.push_back(nums[j]);
            }
            ret.push_back(tobepushed);
        }
        
        return ret;
    }
};