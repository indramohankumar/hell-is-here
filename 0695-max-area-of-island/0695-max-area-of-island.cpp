class Solution {
public:
int  m ;
int n ;
int count ;
void dfs(vector<vector<int>> &grid, int i ,int j ){
    if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){
        return ;
    }
    grid[i][j]=0;
    count++;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int maxi=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    count=0;
                     dfs(grid, i, j);
                }
                maxi=max(maxi,count);
            }
        }
        return maxi ;
    }
};