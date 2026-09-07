class Solution {
public:
    int countRotations(string s, int k) {
        string temp = s + s;
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int score = 0;
            for(int j=i; j<i+n-1; j++){
                if(temp[j]==temp[j+1]){
                    score++;
                }
            }
            if(score == k){ans++;}
        }
        return ans;
    }
};