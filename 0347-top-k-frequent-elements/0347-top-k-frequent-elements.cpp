class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        } 
        vector<int> ans;
        priority_queue<pair<int,int>>pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};