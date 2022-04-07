class Solution {
public:
    int change(int sum, vector<int>& coin) {
        int n = coin.size();
        int t[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(j==0)t[i][j] = 1;
                else if(i==0) t[i][j] = 0;
                else{
                    if(coin[i-1] <= j){
                        t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
                    }else t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};