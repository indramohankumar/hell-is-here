class Solution {
public:
bool dfs(int node ,vector<vector<int>>&graph ,vector<int>& visited,vector<int>& ans){
    visited[node]=1;
    for(int i =0;i<graph[node].size();i++){
        int next=graph[node][i];
        if(visited[next]==1) return false ;
        if(visited[next]==0){
            if(dfs(next,graph,visited,ans)==false)
            return false ;

        }
    }
    visited[node]=2;
    ans.push_back(node);
    return true ;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(int i =0;i<prerequisites.size();i++){
          int course=prerequisites[i][0];
            int prerequisite=prerequisites[i][1];
            graph[prerequisite].push_back(course);
        }
        vector<int>visited(numCourses,0);
        vector<int> ans;
        for(int i =0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,graph,visited,ans)==false)
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans ;
        
    }
};