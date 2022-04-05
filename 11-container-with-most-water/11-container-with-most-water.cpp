class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0, j=h.size()-1;
        long long ans=INT_MIN;
        while(i<j){
            // cout<<(j-i)<<" "<<min(h[i], h[j])<<" ";
            int ind = j-i;
            int mn= min(h[i], h[j]);
            int val=ind*mn;
            ans = max<long long>(ans, val);
            // cout<<ans<<endl;
            if(h[i]<h[j])i++;
            else j--;
        }
        return ans;
    }
};