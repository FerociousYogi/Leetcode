class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        
        for(auto x : nums) {
            m[x] = true;
        }
        
        int max_length = 0;
        for(auto it : m) {
            if(m.find(it.first - 1) != m.end()) continue;
            else {
                int current = it.first;
                int len = 1;
                while(m.find(++current) != m.end()) len++;
                max_length = max(max_length, len);
            }
        }
        
        return max_length;
    }
};