class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int n =grades.size();
        int i=1,ans=0;
        while(n>=i){
            n -= i++;
            ans++;
        }
        return ans;
    }
};