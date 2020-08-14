class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        vector<int> row; vector<int> column;
        for(int i = 0; i < r; i++) {
            int maximum = 0;
            for(int j = 0; j < c; j++) {
                maximum = max(maximum, grid[i][j]);
            }
            row.push_back(maximum);
        }
        
        for(int j = 0; j < c; j++) {
            int maximum = 0;
            for(int i = 0; i < r; i++) {
                maximum = max(maximum, grid[i][j]);
            }
            column.push_back(maximum);
        }
        
        for(auto x : row) {
            cout << x << endl;
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                count += min(row[i], column[j]) - grid[i][j];
            }
        }
        
        return count;
    }
};