class Solution {
public:
    int trap(vector<int>& arr) {
        int n= arr.size();
        int i=0,j=n-1,lm=0,rm=0,ans=0;
        while(i<j){
            if(arr[i]<=arr[j]){
                if(lm<arr[i])lm = arr[i];
                else{
                    ans+= lm-arr[i];
                }
                i++;
            }else{
                if(rm<arr[j])rm = arr[j];
                else{
                    ans += rm - arr[j];
                }
                j--;
            }
        }
        return ans;
    }
};