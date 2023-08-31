class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n = nums.size();
        int count=0;
        int ans=0;
        while(r<n){
            if(nums[r]==1)
            count++;
            while(l<=r && r-l+1-count>k){
                if(nums[l]==1)
                count--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};