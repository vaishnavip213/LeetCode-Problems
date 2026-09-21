class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[r] = number of subarrays ending at previous position
        // whose product % k == r
        vector<long long> dp(k, 0);

        // Answer for all subarrays
        vector<long long> result(k, 0);

        for (int num : nums) {
            int val = num % k;

            // New dp for subarrays ending at current element
            vector<long long> newDp(k, 0);

            // Start a new subarray containing only nums[i]
            newDp[val]++;

            // Extend all previous subarrays by current element
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * val) % k;
                    newDp[newRemainder] += dp[r];
                }
            }

            // Add current subarrays to the final answer
            for (int r = 0; r < k; r++) {
                result[r] += newDp[r];
            }

            // Move to next position
            dp = newDp;
        }

        return result;
    }
};