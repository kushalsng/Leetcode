class Solution {
public:
    bool canTransform(string s, string t) {
        int i=0,j=0, n = s.size();
        while(true){
            while(i<n && s[i] == 'X') i++;
            
            while(j<n && t[j] == 'X') j++;
            if(i>=n || j>=n) break;
            
            // if(i<n && j<n){
                if(s[i] != t[j]) return false;
                if(s[i] == 'L' && i < j) return false;
                if(s[i] == 'R' && i > j)return false;
                i++,j++;
            // }
            
        }
        // cout<<i<<" "<<j;
        
        return i == j;
    
    }
};