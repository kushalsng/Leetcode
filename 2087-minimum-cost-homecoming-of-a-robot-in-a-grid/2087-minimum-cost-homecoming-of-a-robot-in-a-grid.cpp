class Solution {
public:
    void f1(int a, int b, int &ans,vector<int>& rc){
        for(int i=a; i<=b; i++){
            ans += rc[i];
        }
    }
    void f2(int a, int b, int &ans,vector<int>& cc){
        for(int i=a; i<=b; i++){
            // cout<<cc[i]<<" ";
            ans += cc[i];
        }
    }
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int ans=0;
        if(sp[0] == hp[0] && sp[1] == hp[1]) return ans;
        if(sp[0] < hp[0]){
            f1(sp[0]+1, hp[0], ans, rc);
        }else {
            f1(hp[0], sp[0]-1, ans, rc);
        }
        if(sp[1] < hp[1]){
            f2(sp[1]+1, hp[1], ans, cc);
        }else {
            // cout<<"hi";
            f2(hp[1], sp[1]-1, ans, cc);
        }
        // cout<<ans;
        return ans;
    }
};