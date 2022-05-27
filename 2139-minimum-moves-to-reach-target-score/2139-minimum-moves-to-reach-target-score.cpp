class Solution {
public:
    int minMoves(int target, int k) {
        int ans=0;
        while(k && target>1){
            ans++;
            if(target%2)target--;
            else{
                target /=2 ;
                k--;
            }
            
        }
        ans += target-1;
        return ans;
    }
};