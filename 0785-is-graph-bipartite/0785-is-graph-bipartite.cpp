class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n=graph.size();
      for(int i =0;i<n;i++){
        vector<int>color(n,-1);
        if(color[i]!=-1) continue;
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for( int j =0;j<graph[node].size();j++){
                int neighbour=graph[node][j];
            if(color[neighbour]==-1){
                color[neighbour]=1-color[node];
                q.push(neighbour);
            }
            else if(color[neighbour]==color[node]){
                return false ;
            }
            }
        }
      } 
      return true;
    }
};