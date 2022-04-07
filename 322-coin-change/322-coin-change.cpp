class Solution {
public:
    int coinChange(vector<int>& coin, int sum) {
        int n=coin.size();
        int t[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) t[i][j] = INT_MAX -1;
                else if(j==0) t[i][j] = 0;
                else if(i==1){
                    if(j%coin[i-1]==0)t[i][j] = j/coin[i-1];
                    else t[i][j] = INT_MAX -1;
                }else{
                    if(coin[i-1] <= j){
                        t[i][j] = min(t[i][j - coin[i-1]]+1, t[i-1][j]);
                    }
                    else t[i][j] = t[i-1][j];
                }
                
            }
        }
        return t[n][sum] >= INT_MAX-1 ? -1 : t[n][sum];
    }
};