class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        if(num == 0) return ret;
    
        ret[1] = 1;
        for(int i = 1; i < num/2; i++) {
            ret[2*i] = ret[i];
            ret[2*i + 1] = ret[i] + 1;
        }
        
        if(num % 2 == 0) ret[num] = ret[num/2];
        else {
            ret[num] = ret[(num-1)/2] + 1;
            ret[num-1] = ret[(num-1)/2];
        }
        
        return ret;
    }
};