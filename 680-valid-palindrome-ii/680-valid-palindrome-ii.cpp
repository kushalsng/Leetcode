class Solution {
public:
    bool helper(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++,j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0, j= s.size()-1;
        while(i<j && s[i] == s[j]){
            // cout<<s[i]<<" "<<s[j]<<endl;
            ++i,--j;
            
        }
        if(abs(i-j) <2) return true;
        
        return helper(s, i+1, j) || helper(s,i,j-1);
    }
};