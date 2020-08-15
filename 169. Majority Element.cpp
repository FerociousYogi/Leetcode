/*
Boyer-Moore Voting Algorithm
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int curr = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == curr) count++;
            else {
                if(count > 0) count--;
                else {
                    curr = nums[i];
                    count = 1;
                }
            }
        }
        
        return curr;
    }
};