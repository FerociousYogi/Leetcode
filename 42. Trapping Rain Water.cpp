// Dynamic Programming Solution:
class Solution {
public:    
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        
        int max_height = 0;
        for(int i = 0; i < height.size(); i++) {
            max_height = max(max_height, height[i]);
            left[i] = max_height;
        }
        
        max_height = 0;
        for(int i = height.size()-1; i >= 0; i--) {
            max_height = max(max_height, height[i]);
            right[i] = max_height;
        }
        
        int ret = 0;
        for(int i = 0; i < height.size(); i++) {
            ret += max(0, min(left[i], right[i]) - height[i]);
        }
        
        return ret;
    }
};

// Stacks Solution:
