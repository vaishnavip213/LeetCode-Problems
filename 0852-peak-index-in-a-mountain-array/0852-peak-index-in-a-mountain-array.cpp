class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        //BRUTE - FORCE O(n)
        int maxi = *max_element(arr.begin(), arr.end());
        int ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==maxi){ans = i;}
        }
        return ans;
    }
};