class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int maxleft = nums[0];
        int maxright = nums[0];
        vector<int>peak;
        int peaksum = 0;
        int valleysum = 0;
        for(int i=1; i<n-1; i++){
            if((i==0 || nums[i]>nums[i-1]) && (i==n-1 || nums[i]>nums[i+1])){
                peaksum += nums[i];
            }
            if((i==0 || nums[i]<nums[i-1]) && (i==n-1 || nums[i]<nums[i+1])){
                valleysum += nums[i];
            }
        }
        return peaksum - valleysum;
    }
};