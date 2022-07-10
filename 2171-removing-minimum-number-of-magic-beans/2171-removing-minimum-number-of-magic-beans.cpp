class Solution {
public:
    typedef long long ll;
    long long minimumRemoval(vector<int>& arr) {
        ll sum=0;
        for(auto x: arr)sum+= x;
        sort(arr.begin(),arr.end());
        ll lt = 0;
        ll tans=0;
        ll ans =LONG_LONG_MAX;
        for(int i=0; i<arr.size(); i++){
            tans = lt;
            ll tsum = sum - (lt + arr[i]);
            tans += tsum - (arr[i] * (arr.size()-i-1));
            ans = min(ans,tans);
            lt += arr[i];
        }
        return ans;
    }
};