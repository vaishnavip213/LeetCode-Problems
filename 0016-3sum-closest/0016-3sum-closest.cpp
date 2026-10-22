class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int result = nums[0]+nums[1]+nums[2];
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            int  j = i + 1;
            int k = nums.size()-1;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-result)){
                    result = sum;
                }
                if(sum==target){return sum;}
                else if(sum<target){j++;}
                else{k--;}
            }
        }
        return result;
    }
};