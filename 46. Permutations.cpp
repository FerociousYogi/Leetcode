class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        
        if(nums.size() == 0) return ret;
        
        if(nums.size() == 1) {
            ret.push_back(nums);
            return ret;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> newvec = nums;
            newvec.erase(newvec.begin() + i);
            vector<vector<int> > tobepushed = permute(newvec);
            
            for(auto x : tobepushed) {
                x.push_back(nums[i]);
                ret.push_back(x);
            }
        }
        
        return ret;
    }
};