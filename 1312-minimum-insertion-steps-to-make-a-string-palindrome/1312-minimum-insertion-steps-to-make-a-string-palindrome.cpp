class Solution {
public:
    int minInsertions(string x) {
        int n = x.size();
        if(n==1)return 0;
        string y = x;
        reverse(y.begin(),y.end());
        int t[n+1][n+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0)t[i][j] = 0;
                else if(x[i-1] == y[j-1])t[i][j] = t[i-1][j-1] +1;
                else t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        int lcs = t[n][n];
                cout<<lcs<<endl;
        // int ans = lcs %2 ? n - lcs : n-lcs;
        
        return n-lcs;
    }
};