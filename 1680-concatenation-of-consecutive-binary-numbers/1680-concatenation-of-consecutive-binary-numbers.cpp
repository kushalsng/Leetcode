class Solution {
public:
    int lastSet(int x){
        int cnt=0;
        for(int i=20;i>=0; i--){
            if((x&(1<<i)))return i+1;
        }
        return 0;
    }
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long long ans=0;
        for(int i=1;i<=n; i++){
            int last = lastSet(i);
            
            ans = ((ans<<last)|i);
            ans %= mod;
            // cout<<ans<<" ";
        }
        return ans;
    }
};