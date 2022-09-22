class Solution {
public:
    void rev(string &s, int l, int r) {
        int i=l,j=r;
        while(i<j)
            swap(s[i++],s[j--]);
    }
    string reverseWords(string s) {
        int l=0,r=1;
        int i=0,j=0;
        while(j<s.size()){
            if(s[j] != ' ' )j++;
            else{
                rev(s,i,j-1);
                i=j+1;
                j++;
            }
        }
        rev(s,i,j-1);
        return s;
    }
};