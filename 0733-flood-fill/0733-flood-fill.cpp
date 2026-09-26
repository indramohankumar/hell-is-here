class Solution {
public:
int m ;
int n ;
void dfs(vector<vector<int>> &image ,int i ,int j,int newcolor ,int oldcolor){
    if(i<0||i>=m||j<0||j>=n){
        return ;
    }
    if(image[i][j]!=oldcolor){
        return ;
    }
    image[i][j]=newcolor;
     dfs(image, i+1, j, newcolor, oldcolor);
        dfs(image, i-1, j, newcolor, oldcolor);
        dfs(image, i, j+1, newcolor, oldcolor);
        dfs(image, i, j-1, newcolor, oldcolor);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int oldcolor=image[sr][sc];
        if(oldcolor==color){
            return image ;
        }
        
            dfs(image,sr,sc,color,oldcolor);
        return image ;
        
    }
};