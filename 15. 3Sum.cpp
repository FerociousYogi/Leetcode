class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3) return ret;
        
        sort(nums.begin(), nums.end());
        
        for(auto x : nums) cout << x << " ";
        cout << endl;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
                i++;
            }
            
            if(i >= nums.size() - 2) break;
            
            int left = i+1; int right = nums.size() - 1;
            int sum;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                     
                if(sum == 0) {
                    vector<int> to_push = {nums[i], nums[left], nums[right]};
                    ret.push_back(to_push);
                    while(left + 1 <= right && nums[left + 1] == nums[left]) left++;
                    while(left <= right - 1 && nums[right - 1] == nums[right]) right--;
                    
                    left++; right--;
                }
                else if(sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return ret;
    }
};