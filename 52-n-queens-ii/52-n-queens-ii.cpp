class Solution {
public:
    void solve(int c, int n, int&ans,vector<string> &board, vector<int>& rows, vector<int>&d1, vector<int>&d2){
        if(c == n){
            ans++;return;
        }
        for(int r=0; r<n; r++){
            if(!rows[r] && !d1[r+c] && !d2[n-1+c-r]){
                board[r][c] = 'Q';
                rows[r] =1;
                d1[r+c] =1;
                d2[n-1+c-r] =1;
                solve(c+1,n,ans,board,rows,d1,d2);
                board[r][c] = '.';
                rows[r] =0;
                d1[r+c] =0;
                d2[n-1+c-r] =0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        vector<int> rows(n),d1(2*n-1),d2(2*n-1);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0,n,ans,board,rows,d1,d2);
        return ans;
    }
};