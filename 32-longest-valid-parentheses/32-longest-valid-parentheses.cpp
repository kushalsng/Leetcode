class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,tans=0;
        stack<pair<char,int>> st;
        set<int> os;
        for(int i =0; i<s.size(); i++){
            if(s[i] == '('){
                st.push({s[i], i});
            }else if(!st.empty() && st.top().first == '('){
                os.insert(i);
                os.insert(st.top().second);
                st.pop();
            }
        }
        auto it = os.begin();
        if(it == os.end())return 0;
        int prev = *it;
        it++;
        while(it!=os.end()){
            if(*it  == prev+1){
                if(tans==0) tans+=2;
                else tans++;
            }
            else ans = max(tans,ans), tans=0;
            prev = *it;
            it++;
        }
        ans = max(tans,ans);
        return ans;
    }
};