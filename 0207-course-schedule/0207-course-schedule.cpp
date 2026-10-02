class Solution {
public:
bool dfs(int node,vector<vector<int>>&graph,vector<int>&visited){
    visited[node]=1;
    for(int i=0;i<graph[node].size();i++){
        int next=graph[node][i];
        if(visited[next]==1) return false ;
        if(visited[next]==0) {
            if(dfs(next,graph,visited)==false)
            return false ;
        }
    }
    visited[node]=2;
    return true ;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int prerequisite=prerequisites[i][1];
            graph[prerequisite].push_back(course);

        }
        vector<int>visited(numCourses,0);
        for(int i =0;i <numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,graph,visited)==false)
                return false;
            }
        }
        return true ;
    }
};