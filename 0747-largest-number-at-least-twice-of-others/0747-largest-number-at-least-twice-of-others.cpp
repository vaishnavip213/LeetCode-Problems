class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // map<int,int>mpp;
        // for(int i=0; i<nums.size(); i++){
        //     mpp[nums[i]]++;
        // }
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // if(nums[n-1] >= (2*nums[n-2])){
        //     return mpp[nums[n-1]];
        // }
        // return -1;
        //2nd Approach
        int large = -1;
        int slarge = -1;
        int index = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>large){
                slarge = large;
                large = nums[i];
                index = i;
            }
            else if(nums[i]>=slarge && nums[i]<large){
                slarge = nums[i];
            }
        }
        if(large >= 2*slarge){
            return index;
        }
        return -1;
    }
};