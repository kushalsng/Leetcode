class Solution {
    int t[20];
public:
    int numTrees(int n) {
        memset(t,-1,sizeof t);
        t[0] = 1, t[1] = 1, t[2] = 2;
        long sum =0;
        for(int i=1; i<=n; i++){
            if(t[i-1] == -1) t[i-1] = numTrees(i-1);
            if(t[n-i] == -1) t[n-i] = numTrees(n-i);
            sum += t[i-1]*t[n-i];
        }
        return sum;
    }
};