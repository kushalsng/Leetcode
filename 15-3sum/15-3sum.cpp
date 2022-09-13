class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        if(n<3)return ans;
        sort(a.begin(), a.end());
        for(int i=0; i<a.size()-2; i++){
            int l = i+1, r = n-1;
            if(i == 0 || a[i] !=a[i-1]){
                while(l<r){
                    if(a[l] +a[r] == -a[i]){
                        ans.push_back({a[l++], a[r--], a[i]});
                        while(l<r and a[l] == a[l-1])l++;
                        while(l<r and a[r] == a[r+1])r--;
                    }else if(-a[i] < a[l] + a[r]) r--;
                    else l++;
                }
            }
            
        }
        return ans;
    }
};