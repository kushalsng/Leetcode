class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,int n,vector<int>&cols,vector<int>&up,vector<int>&low){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(!cols[row] && !low[row +col] && !up[n-1+col-row]){
                board[row][col] = 'Q';
                cols[row] =1;
                up[n-1+col-row] = 1;
                low[row+col] =1;
                solve(col+1, board,ans,n,cols,up,low);
                board[row][col] = '.';
                cols[row] = 0;
                up[n-1+col-row] = 0;
                low[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> cols(n), up(2*n-1), low(2*n-1);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        solve(0,board,ans,n,cols,up,low);
        return ans;
    }
};