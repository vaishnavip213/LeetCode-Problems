class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis,int* delrow,int* delcol){
        vis[r][c]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        //for first and last row to check boundry 0s
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis,delrow,delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis,delrow,delcol);
            }
        }
        //for first and last col to check boundry 0s
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis,delrow,delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis,delrow,delcol);
            }
        }
        //Remaining non-boundry regioned 0s
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};