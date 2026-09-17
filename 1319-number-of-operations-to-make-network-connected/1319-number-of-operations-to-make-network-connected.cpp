class DisjointSet{
    public : 
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(parent[x]!=x){
            parent[x]=findParent(parent[x]);
        }
        return parent[x];
    }
    void UnionByRank(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv){return;}
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        DisjointSet ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u)==ds.findParent(v)){
                extra++;
            }
            else{
                ds.UnionByRank(u,v);
            }
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i){comp++;}
        }
        int ans = comp-1;
        if(extra >= ans){return ans;}
        else{return -1;}
    }
};