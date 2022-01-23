class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        unsigned long long save = left & right;
        while(save>0){
            if((save & (save-1)) == 0) break;
            else save = (save & (save-1));
        }
        unsigned long long res;
        if(right>=save*2) res = 0;
        else{
            res= left;
            for(unsigned long long i =left;i<=right;i++){
                res &= i;
            }
        }
        
        return res;
    }
};
