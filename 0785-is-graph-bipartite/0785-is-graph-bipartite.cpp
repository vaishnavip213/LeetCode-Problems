class Solution {
public:
    bool dfs(int i,int col,vector<vector<int>>& graph,vector<int>&color){
        color[i]=col;
        for(int neigh : graph[i]){
            if(color[neigh]==-1){
                color[neigh]=1-col;
                if(dfs(neigh,1-col,graph,color)==false){return false;}
            }
            else if(color[neigh]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){return false;}
            }
        }
        return true;
    }        
};