class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        int n= s.size();
        int ans=0;
        while(i<n){
            if(s[i]== '0'){
                i++;
                ans++;
            }else if (i+1<n){
                ans++;
                int j=i;
                while(j<n && s[j] == '1'){
                    s[j] = '0';
                    j++;
                }
                if(j<n)s[j] ='1';
                ans+= j-i;
                i = j;
            }else i++;
        }
        return ans;
    }
};