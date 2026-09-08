class Solution {
public:
    int countDigits(int num){
        int cnt = 0;
        while(num>0){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
    int countCommas(int n) {
        int digitcnt = countDigits(n);
        if(digitcnt<4){return 0;}
        int ans = 0;
        for(int i=1; i<=n; i++){
            int commas = 0;
            digitcnt = countDigits(i);
            if(digitcnt<4){commas=0;}
            else{
                commas = digitcnt/3;
                if(digitcnt%3==0){
                commas = commas-1;
                }
            }
            ans = ans + commas;
        }
        return ans;
    }
};