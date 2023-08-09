class Solution {
public:
    bool possible(vector<int>&nums,int p, int md){
        int i=0;
        int n = nums.size();
        int count=0;
        while(i<n){
            if(i+1<n && abs(nums[i]-nums[i+1])<=md){
                count++;
                i+=2;
            }
            else i++;
        }
        if(count>=p)
        return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l = 0,h=abs(nums[0]-nums.back());
        int ans=0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(nums, p,mid)){
                ans = mid;
                h = mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};