//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int fun(string &s1, string &s2, int p, int q,vector<vector<int>>&dp){
        if(p<0 || q<0)
        return 0;
        if(dp[p][q]!=-1)
        return dp[p][q];
        int take = 0;
        int nottake = 0;
        if(s1[p]==s2[q]){
            take = 1+fun(s1,s2,p-1,q-1,dp);
        }
        else{
            nottake = fun(s1,s2,p-1,q,dp);
            nottake = max(nottake,fun(s1,s2,p,q-1,dp));
        }
        return dp[p][q] = max(take, nottake);
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s1,s2,n-1,m-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends