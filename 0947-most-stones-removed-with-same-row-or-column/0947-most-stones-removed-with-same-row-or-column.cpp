class DisjointSet{
    public : 
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow =  0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol , it[1]);
        }
        unordered_map<int,int>stoneNodes;
        DisjointSet ds(maxRow+maxCol+1);
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.UnionByRank(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int comp = 0;   //To find count of ultimate parents
        for(auto it : stoneNodes){
            if(ds.findParent(it.first)==it.first){
                comp++;
            }
        }
        return n-comp;
    }
};