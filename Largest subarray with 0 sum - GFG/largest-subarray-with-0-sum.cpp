//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        vector<int> pfx(n);
        unordered_map<int,int> mp;
        int ans =0;
        for(int i=0; i<n; i++){
            if(i==0)pfx[i] = nums[i];
            else pfx[i] = pfx[i-1] + nums[i];
            if(pfx[i] == 0)ans = max(ans, i+1);
        }
        for(int i=0; i<n; i++){
            if(mp.count(pfx[i])){
                ans = max(ans, i - mp[pfx[i]]);
            } else {
                mp[pfx[i]] = i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends