class Solution {
public:
    bool isSafe(int i, int j, int n, int m, vector<vector<char> >& grid, vector<vector<bool> >& visited) {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m) && (grid[i][j] == '1') && !visited[i][j];
    }
    
    
    void BFS(int i, int j, int n, int m, vector<vector<char> >& grid, vector<vector<bool> >& visited) {
        queue<pair<int, int> > q;
        q.push({i, j});
        
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if(visited[curr.first][curr.second]) continue;
            visited[curr.first][curr.second] = true;
            if(isSafe(curr.first-1, curr.second, n, m, grid, visited)) q.push({curr.first-1, curr.second});
            if(isSafe(curr.first+1, curr.second, n, m, grid, visited)) q.push({curr.first+1, curr.second});
            if(isSafe(curr.first, curr.second-1, n, m, grid, visited)) q.push({curr.first, curr.second-1});
            if(isSafe(curr.first, curr.second+1, n, m, grid, visited)) q.push({curr.first, curr.second+1});
        }
        
        return;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        
        int m = grid[0].size();
        if(m == 0) return 0;
        
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((grid[i][j] == '1') && !visited[i][j]) {
                    BFS(i, j, n, m, grid, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};