// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0; i<n;i++){
	        sum += arr[i];
	    }
	    int save = sum;
	    sum /= 2;
	    int t[n+1][sum+1];
	    
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<sum+1; j++){
	            if(i==0 || j==0) t[i][j] = 0;
	            else{
	                if(arr[i-1] <= j){
	                    t[i][j] = max(arr[i-1] + t[i-1][j-arr[i-1]], t[i-1][j]);
	                }else t[i][j] = t[i-1][j];
	            }
	        }
	    }
	   // cout<<save - t[n][sum]<<endl;
	    return abs(t[n][sum] - (save- t[n][sum]));
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends