class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>st(nums.begin(),nums.end());
        vector<int>arr (st.begin(),st.end());
        int l=0;
        int r=0;
        int ans=INT_MAX;
        while(r<arr.size()){
            while(l<=r && arr[r]>arr[l]+n-1){
                l++;
            }
            ans=min(ans,n-(r-l+1));
            if(l>r)
            l=r;
            r++;
        }
        return ans;
    }
};