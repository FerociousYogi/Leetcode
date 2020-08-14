class Solution {
public:
    vector<int> grayCode(int n) {
        int c = pow(2,n);
        vector<int> ans(c);
        
        for(int i=0;i<c;i++) {
            ans[i]=i^(i>>1);
        }
        
        return ans;
    }
};