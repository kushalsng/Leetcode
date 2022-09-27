class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size();
        int i=0,j=1;
        while(j<n){
            if(s[j] == '.')j++;
            else if(s[j] == 'L' and s[i] == '.'){
                while(i<j)s[i++] = 'L';
                j++;
            }
            else if((s[i] == 'L' or s[i] == '.') and (s[j] == 'R')){
                i = j;
                j++;
            }else if(s[i] == 'R' and s[j] == 'L'){
                int len = j -i-1;
                int half = len/2;
                i++;
                if(len%2==0){
                    // cout<<i<<" "<<j<<", ";
                    while(half--)s[i++] = 'R';
                    half = len/2;
                    while(half--)s[i++] = 'L';
                    // cout<<i<<" "<<j<<", ";
                }else{
                    while(half--)s[i++] = 'R';
                    i++;
                    half = len/2;
                    while(half--)s[i++] = 'L';
                }
                j++;
            }else if(s[i] == s[j]){
                while(i<j)s[i++] = s[j];
                j++;
            }
        }
        if(i<n and s[i] == 'R'){
            // cout<<"hi";
            while(i<n)s[i++] = 'R';
        }
        return s;
    }
};