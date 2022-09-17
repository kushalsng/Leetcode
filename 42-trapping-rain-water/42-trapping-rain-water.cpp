class Solution {
public:
    int trap(vector<int>& arr) {
        int n= arr.size();
        vector<int> prev(n), nxt(n);
        prev[0] = arr[0];
        for(int i=1;i<n;i++){
            prev[i] = max(prev[i-1],arr[i]);
        }
        
        nxt[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            nxt[i] = max(nxt[i+1],arr[i]);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += min(prev[i],nxt[i]) - arr[i];
        }
        return ans;
    }
};