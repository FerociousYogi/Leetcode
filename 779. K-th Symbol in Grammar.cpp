class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        
        int ret;
        
        if (K > pow(2, N-2)) {
            ret = 1;
            K -= pow(2, N-2);
            N--;
        }
        else {
            ret = 0;
            N--;
        }
        
        while (K > 2) {
            if (K > pow(2, N-2)) {
                if (ret == 1) ret = 0;
                else ret = 1;
                
                K -= pow(2, N-2);
                N--;
            }
            else {
                if (ret == 1) ret = 1;
                else ret = 0;
                
                N--;
            }
        }
        
        if (K == 1) return ret;
        else return (ret + 1) % 2;
    }
};