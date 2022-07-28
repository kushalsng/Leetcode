class Solution {
public:
    int m,n;
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n,0));
        vector<vector<int>> cur(n, vector<int>(n,0));
        for(int j1 =0; j1<n;j1++){
            for(int j2 = 0; j2<n; j2++){
                if(j1 == j2) front[j1][j2] = grid[m-1][j1];
                else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i = m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int mx = -1e8;
                    for(int x = -1; x<=1; x++){
                        for(int y= -1; y<=1; y++){
                            int val =0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];
                            if(j1+x>=0 && j1+x<n && j2+y>=0 && j2+y<n)
                                val += front[j1+x][j2+y];
                            else val += -1e8;
                            
                            mx = max(mx, val);
                        }
                    }
                    cur[j1][j2] = mx;
                }
            }
            front = cur;
        }
        return cur[0][n-1];
    }
};