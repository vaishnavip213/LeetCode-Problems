class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //OPTIMAL O(n)
        int n = nums.size();
        vector<int>suffixmin(n);
        suffixmin[n - 1] = nums[n - 1];
        for(int i=n-2; i>=0; i--){
            suffixmin[i]=min(nums[i],suffixmin[i+1]);
        }
        int prefixmax = nums[0];
        for(int i=0; i<n; i++){
            prefixmax = max(nums[i],prefixmax);
            if(prefixmax - suffixmin[i] <= k){
                return i;
            }
        }
        return -1;


        //BRUTE-FORCE O(n^2)
        /*for(int i=0; i<nums.size(); i++){
            int maxi = *max_element(nums.begin(),nums.begin()+i+1);
            int mini = *min_element(nums.begin()+i,nums.end());
            if(maxi-mini <= k){
                return i;
            }
        }
        return -1;*/
    }
};