class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mpp;
        int n =grid.size();
        int count=0;
        for(int i =0;i<n;i++){//store every row 
            mpp[grid[i]]++;
        }
        for(int j =0;j<n ;j++){
            vector<int>col;
            //extract the coloumn 
            for(int i =0;i<n ;i++){
                col.push_back(grid[i][j]);
            }
            if(mpp.find(col)!=mpp.end()){
                count+=mpp[col];
            }
        }
        return count;
    }
};