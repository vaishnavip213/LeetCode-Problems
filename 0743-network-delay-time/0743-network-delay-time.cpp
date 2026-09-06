class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            for(auto& iter : adj[node]){
                int adjnode = iter.first;
                int wt = iter.second;
                if(time + wt < dist[adjnode]){
                    dist[adjnode] = time + wt;
                    pq.push({time + wt, adjnode});
                }
            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        if(ans == 1e9){return -1;}
        return ans;
    }
};