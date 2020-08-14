class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n);
        
        for (int i = 0; i < n; i++) {
            ret[i].resize(n, 0);    
        }
        
        int counter = 1;
        int i = 0, j = 0;
        
        for(int i = 0; i <= n/2; i++) {
            fill(i, n, counter, ret);
        }
        
        return ret;
    }
    
    void fill(int c, int n, int &counter, vector<vector<int> > &arr) {
        for(int j = c; j < n-c; j++) {
            arr[c][j] = counter++;
        }
        
        for(int i = 1+c; i < n-c; i++) {
            arr[i][n-1-c] = counter++;
        }
        
        for(int j = n-2-c; j >= c; j--) {
            arr[n-1-c][j] = counter++;
        }
        
        for(int i = n-2-c; i > c; i--) {
            arr[i][c] = counter++;
        }
        
        return;
    }
};

