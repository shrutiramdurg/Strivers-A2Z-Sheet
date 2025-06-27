class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;

 
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

   
        while(!q.empty() && fresh > 0){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front(); q.pop();
                for(auto& [dx, dy] : dirs){
                    int nx = x + dx, ny = y + dy;
                    if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
