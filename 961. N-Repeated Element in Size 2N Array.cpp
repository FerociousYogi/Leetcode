class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i = 0; i < A.size() - 3; i++) {
            if(A[i] == A[i+1] || A[i] == A[i+2] || A[i] == A[i+3]) {
                return A[i];
            }
            else if(A[i+1] == A[i+2] || A[i+1] == A[i+3]) {
                return A[i+1];
            }
            else if(A[i+2] == A[i+3]) {
                return A[i+2];
            }
        }
        return -1;
    }
};