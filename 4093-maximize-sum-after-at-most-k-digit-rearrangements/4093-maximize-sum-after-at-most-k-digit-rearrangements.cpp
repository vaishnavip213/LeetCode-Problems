class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end() , greater<int>());
        int i =0 ;
        long long sum = 0;
        for(int i=0; i<n; i++){sum += nums[i];}
        vector<int>diff;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            string str = to_string(num);
            sort(str.begin() , str.end() , greater<int>());
            num = stoi(str);
            int dif = num - nums[i];
            diff.push_back(dif);
        }
        sort(diff.begin() , diff.end() , greater<int>());
        for(int i=0; i<k; i++){
            sum += diff[i];
        }
        return sum;
    }
};