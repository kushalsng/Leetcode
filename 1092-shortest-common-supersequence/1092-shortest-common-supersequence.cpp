class Solution {
public:
    string shortestCommonSupersequence(string x, string y) {
        int m = x.size(), n = y.size();
        int t[m+1][n+1];
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0) t[i][j]=0;
                else if(x[i-1]==y[j-1]) t[i][j] = t[i-1][j-1] +1;
                else t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        int i=m,j=n;
        string lcs = "";
        while(i>0 && j>0){
            if(x[i-1] == y[j-1]) {
                lcs = x[i-1] + lcs;
                i--,j--;
            }
            else if(t[i-1][j]>t[i][j-1]){
                lcs = x[i-1] + lcs;
                i--;
            }
            else {
                lcs = y[j-1] + lcs;
                j--;
            }
        }
        while(i>0){
            lcs = x[i-1] + lcs;
            i--;
        }
        while(j>0){
            lcs = y[j-1] + lcs;
            j--;
        }
        return lcs;
    }
};