class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            while(nums[i]!=maxi){
                nums[i] += 1;
                move++;
            }
        }
        return move;
    }
};