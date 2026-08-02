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
                else if(path[v]){
                    return true;  
                }
            }
        }
        path[src]=false;
        return false;
    }
    void toposort(int src, vector<bool>&vis2,stack<int>&st,vector<vector<int>>& graph){
        vis2[src]=true;
        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u==src){
                if(!vis2[v]){
                    toposort(v,vis2,st,graph);
                }
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int v = numCourses;
        vector<bool>vis(v,false);
        vector<bool>path(v,false);
        vector<int>ans;
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(isCycle(i,vis,path,graph)){return ans;}
            }
        }
        vector<bool>vis2(v,false);
        stack<int>st;
        for(int i=0; i<v; i++){
            if(!vis2[i]){
                toposort(i,vis2,st,graph);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};