class Solution {
public:
    string simplifyPath(string s) {
        // int n = s.size();
        
        for(int i=0;i<s.size();){
            if(s[i] == '/'){
                while(i+1<s.size() && s[i+1] == '/') s.erase(s.begin() + i+1);
                

                if(i+3<=s.size() && s[i+1] == '.'){
                    

                    if(
                        (i+3 < s.size() && s[i+2] == '.' && s[i+3]== '/') ||
                        (i+3 == s.size() && s[i+2] == '.')
                    ){
                        // cout<<"i= "<<i<<", S= "<<s<<endl;
                        
                        int j = (i-1 < 0) ? i+1 : i-1;
                        while(j>=0 && s[j] != '/')j--;
                        
                        i+3 < s.size() ? s.erase(s.begin() + j+1, s.begin() + i+4)
                            : s.erase(s.begin() + j+1, s.begin() + i+3);
                        i = j;
                    }
                    else if(s[i+2] == '/'){
                        s.erase(s.begin()+i+1, s.begin()+i+3);
                    }
                    else i++;
                } else i++;
            }
            else i++;
        }
        if(
            (s.size() > 1 && s[s.size()-1] == '/') ||
            (s.size() >= 2 && s[s.size()-1] == '.' && s[s.size()-2] == '/')
        )s.pop_back();
        if(s.size() > 1 && s[s.size()-1] == '/')s.pop_back();
        return s;
    }
};