class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int xx[4] = {0, 1, 0, -1};
        int yy[4] = {1, 0, -1, 0};
        int origin = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] =1;
        image[sr][sc]=color;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newx = x+xx[i];
                int newy = y+yy[i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && image[newx][newy]==origin && !vis[newx][newy]){
                    vis[newx][newy]=1;
                    image[newx][newy]=color;
                    q.push({newx, newy});
                }
            }
        }
        return image;
    }
};