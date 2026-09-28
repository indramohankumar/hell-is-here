class Solution {
public:
int m ;
int n;
vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     m=mat.size();
     n=mat[0].size();
     queue<pair<int,int>>q;
     vector<vector<int>>result(m,vector<int>(n,-1));
     for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                result[i][j]=0;
                q.push({i,j});
            }
        }
     }
     while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
        for(auto &dir:directions){
            int newi=i+dir[0];
            int newj=j+dir[1];
            if(newi>=0&& newi<m&&newj>=0&&newj<n&&result[newi][newj]==-1){
                result[newi][newj]=result[i][j]+1;
                q.push({newi,newj});
            }

        }
     }
     return result;
    }
};