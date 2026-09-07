class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        long long totalSum = 0;
        long long firstHalfSum = 0;
        for(int it : nums){totalSum += it;}
        for(int i=0; i<half; i++){firstHalfSum += nums[i];}
        int ans = 0;
        for(int i=0; i<n; i++){
            long long secHalfSum = totalSum - firstHalfSum;
            if(firstHalfSum > secHalfSum){ans++;}
            firstHalfSum -= nums[i];
            firstHalfSum += (nums[(i+half)%n]);
        }
        return ans;
    }
};