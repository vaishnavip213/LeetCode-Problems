class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int even = 0;
        int n = nums1.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini,nums1[i]);
            if(nums1[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even==n || odd==n){return true;}
        if(mini%2==1){return true;}
        return false;
    }
};