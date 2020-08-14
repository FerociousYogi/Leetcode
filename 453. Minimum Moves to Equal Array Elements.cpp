class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ret = 0;
        int min = *(min_element(nums.begin(), nums.end()));
        for(int i = 0; i < nums.size(); i++) {
            ret += nums[i] - min;
        }
        return ret;
    }
};