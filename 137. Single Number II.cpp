class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 30; i >= 0; i--) {
            int sum = 0;
            for(auto x : nums) {
                if(x & 1 << i) sum++;
            }
            
            ret *= 2;
            
            if(sum % 3 != 0) ret += 1;
        }
        
        int sum = 0;    
        for(auto x : nums) {
            if(x & 1 << 31) sum++;
        }
        if(sum % 3 != 0) ret += (1 << 31);
        
        return ret;
    }
};