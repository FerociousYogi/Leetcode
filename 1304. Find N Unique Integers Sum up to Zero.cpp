class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret(n);
        for(int i = 0; i < n/2; i++) {
            ret[i] = i+1;
        }
        for(int i = n/2; i < n/2 * 2; i++) {
            ret[i] = -(i+1 - n/2);
        }
        
        return ret;
    }
};