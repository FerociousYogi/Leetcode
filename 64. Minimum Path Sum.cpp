class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        
        int i = n-1, j = m-1;
        while(i >= 0 && j >= 0) {
            if(!(i == n-1 & j == m-1)) grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            
            int temp_col = j;
            for(; j > 0; j--) {
                if(i == n-1) grid[i][j-1] += grid[i][j];
                else grid[i][j-1] += min(grid[i][j], grid[i+1][j-1]);
            }
            j = temp_col; 
        
            int temp_row = i;
            for(; i > 0; i--) {
                if(j == m-1) grid[i-1][j] += grid[i][j];
                else grid[i-1][j] += min(grid[i][j], grid[i-1][j+1]); 
            }
            i = temp_row;
            
            i--; j--;
        }
        
        return grid[0][0];
    }
};