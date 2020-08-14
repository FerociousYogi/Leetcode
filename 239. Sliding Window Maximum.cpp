class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i = 0; i < k; i++) {
            if(q.empty()) q.push_back(i);
            else {
                while(!q.empty() && nums[q.back()] < nums[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }
        
        vector<int> ret;
        for(int i = 0; i <= nums.size() - k; i++) {
            if(q.front() < i) {
                q.pop_front();
            }
            
            while(!q.empty() && nums[q.back()] <= nums[i+k-1]) {
                q.pop_back();
            }
            q.push_back(i+k-1);
            ret.push_back(nums[q.front()]);
        }
        
        return ret;
    }
};