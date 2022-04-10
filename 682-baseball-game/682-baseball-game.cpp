class Solution {
public:
    int toInt(string s){
        int num = 0;
        int j=0;
        for(int i=s.size()-1;s[0] == '-' ?  i> 0 : i>=0; i--){
            int x = s[i]-'0';
            num += x*pow(10,j++);
        }
        return s[0] == '-' ? -num : num;
    }
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(string s: ops){
            int  n=v.size();
            if(s == "+"){
                v.push_back(v[n-1]+v[n-2]);
            }
            else if(s == "D"){
                v.push_back(v[n-1]*2);
            }else if(s == "C")v.pop_back();
            else{
                v.push_back(toInt(s));
            }
        }
        int ans=0;
        for(auto x: v)ans+= x;
        return ans;
    }
};