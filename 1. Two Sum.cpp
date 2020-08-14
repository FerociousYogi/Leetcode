class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i) {
                vector<int> ret = {i, m[target - nums[i]]};
                return ret;
            }
            m[nums[i]] = i;
        }
        else {
            cerr << "No such pair found";
            exit(1);
        }
    }
};