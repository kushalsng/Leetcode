class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int,string> mp;
        int i=0,j=k-1,n=s.size();
        if(k>n)return false;
        int val=0;
        int ind=0;
        for(int k=j; k>=i; k--){
            if(s[k] == '1')val += pow(2,ind);
            ind++;
        }
        mp.insert({val,s.substr(i,k)});
        while(j+1<n){
            if(s[i] == '1'){
                val -= pow(2,k-1);
            }
            i++;
            val <<= 1;
            j++;
            if(s[j] == '1') val++;
            // cout<<val<<" "<<s.substr(i,k)<<", ";
            mp.insert({val,s.substr(i,k)});
        }
        for(int i = 0; i<pow(2,k); i++){
            if(mp.find(i) == mp.end())return false;
        }
        return true;
    }
};