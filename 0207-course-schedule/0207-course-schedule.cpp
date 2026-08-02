class Solution {
public:
    bool isCycle(int src,vector<bool>&vis,vector<bool>&path,vector<vector<int>>& graph){
        vis[src]=true;
        path[src]=true;
        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,path,graph)){return true;}
                }
                else{
                    if(path[v]){
                        return true;
                    }  
                }
            }
        }
        path[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int v = numCourses;
        vector<bool>vis(v, false);
        vector<bool>path(v, false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(isCycle(i, vis, path, graph)){return false;}
            }
        }
        return true;
    }
};