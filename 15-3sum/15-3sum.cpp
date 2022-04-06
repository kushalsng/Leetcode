class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        if(a.size()<3)return ans;
        sort(a.begin(), a.end());
        for(int i=0; i<a.size()-2; i++){
            int l = i+1, r=a.size()-1;
            if(i==0 || (a[i] != a[i-1])){
                while(l<r){
                    // cout<<l<<" "<<r<<endl;
                    if(a[l] + a[r] == -a[i]){
                        ans.push_back({a[i],a[l++],a[r--]});
                        while(l<r && a[l] == a[l-1]) l++;
                        while(l<r && a[r] == a[r+1]) r--;
                    }else if(-a[i] <a[l]+a[r])r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};