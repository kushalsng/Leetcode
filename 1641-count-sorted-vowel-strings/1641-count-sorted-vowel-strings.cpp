class Solution {
public:
    int t[51][5];
    int countVowelStrings(int n) {
        int lsum=0;
        memset(t,0,sizeof t);
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                if(i==0) t[i][j] = 1, lsum += t[i][j];
                else{
                    if(j==0){
                        t[i][j] = lsum;
                    }else{
                        t[i][j] = t[i][j-1] - t[i-1][j-1];
                        lsum += t[i][j];
                    }
                }
            }
        }
        return lsum;
    }
};