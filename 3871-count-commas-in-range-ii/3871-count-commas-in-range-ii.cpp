class Solution {
public:
    using ll=long long;
    long long countCommas(long long n) {
        ll ans=0;
        for(ll t=1000, d=1; t<=n; t*=1000, d++){
            ll x=min(n+1, 1000*t);
            ans+=(x-t)*d;
        }
        return ans;
    }
};