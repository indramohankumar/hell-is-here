class Solution {
public:
int m ;
int n ;
int closed;
void dfs(vector<vector<int>>&grid,int i ,int j){
    if(i<0||i>=m||j<0||j>=n){
      
        return ;
    }
    if(grid[i][j]==1){
        return ;
    }
     if(i == 0 || i == m-1 || j == 0 || j == n-1) {
            closed = 0;
        }
    grid[i][j]=1;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    closed=1;
                    dfs(grid,i,j);
                    if(closed==1){
                        count++;
                    }
                }

            }
        }
        return count;
    }
};