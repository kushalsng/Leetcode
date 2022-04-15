// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int t[101][101];
public:
    int solve(int arr[], int n, int i, int j){
        if(i>=j)return 0;
        long long ans = LONG_LONG_MAX;
        for(int k = i; k < j; k++){
            int tans=0;
            if(t[i][k] == -1) t[i][k] = solve(arr,n,i,k);
            tans+= t[i][k];
            if(t[k+1][j] == -1) t[k+1][j] = solve(arr,n,k+1,j);
            tans += t[k+1][j];
            tans += arr[i-1]*arr[k]*arr[j];
            ans = min<long long>(ans,tans);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(t,-1,sizeof t);
        long long ans = LONG_LONG_MAX;
        ans = solve(arr, N, 1, N-1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends