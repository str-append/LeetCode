class Solution {
public:
    void recur(int n,int k,int i,vector<int>&temp,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        //its working since I am starting it with 0
        // so j will go from 1 to n;
        for(int j=i+1;j<=n;j++){
            temp.push_back(j);
            recur(n,k-1,j,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        recur(n,k,0,temp,ans);
        return ans;

    }
   
};