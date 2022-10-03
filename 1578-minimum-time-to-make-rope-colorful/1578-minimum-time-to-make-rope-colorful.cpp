class Solution {
public:
    int minCost(string col, vector<int>& time) {
        // cout<<col.size()<<endl;
        int sum =0;
        int mx =0;
        long ans=0;
        // int i=1;
        for(int i=0;i<col.size();i++) {
            if(i>0 and col[i] != col[i-1]){
                ans += sum - mx;
                sum = mx = 0;
            }
            sum += time[i];
            mx = max(mx,time[i]);
        }
        // cout<<sum<<" "<<mx<<",";
        ans += sum - mx;
        return ans;
    }
};