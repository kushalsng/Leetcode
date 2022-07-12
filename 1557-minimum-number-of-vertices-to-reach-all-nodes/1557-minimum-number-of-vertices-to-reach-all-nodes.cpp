class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& ed) {
        vector<int> ans;
        int m = ed.size();
        set<int> s;
        for(int i=0; i<m; i++){
            s.insert(ed[i][1]);
        }
        int i=0;
        for(auto it = s.begin(); it != s.end();){
            if(*it != i)ans.push_back(i++);
            else i++,it++;
        }
        while(i<n)ans.push_back(i++);
        return ans;
    }
};