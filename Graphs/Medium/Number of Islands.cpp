class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;  
        
        int m = grid.size();       
        int n = grid[0].size();    
        
        queue<pair<int,int>> q;    
        
        // Visited array to mark cells we have already processed
        vector<vector<int>> vis(m, vector<int>(n, 0));

        
        int dr[4] = {0, 1, 0, -1}; 
        int dc[4] = {1, 0, -1, 0}; 

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                
                if((!vis[i][j]) && (grid[i][j] == '1')) {

                    q.push({i, j});       
                    ans++;                
                    vis[i][j] = 1;        

                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                               !vis[nr][nc] && grid[nr][nc] == '1') {
                                q.push({nr, nc});     
                                vis[nr][nc] = 1;   
                            }
                        }
                    }
                }
            }
        }
        return ans;  
    }
};