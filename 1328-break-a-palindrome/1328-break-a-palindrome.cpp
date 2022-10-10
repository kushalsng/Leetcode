class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        int mid = n/2;
        for(int i=0;i<n; i++){
            if(s[i] != 'a'){
                if(n%2 and i==mid){
                    if(n==1)return "";
                    else{
                        break;
                    }
                }else{
                    s[i] = 'a';
                    return s;
                }
            }
        }
        if(n == 1)return "";
        s[n-1] = 'b';
        return s;
    }
};