class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)
        return 0;
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int a = INT_MAX;
        a = min(a,abs(nums[0]-nums[n-4]));
        a = min(a,abs(nums[1]-nums[n-3]));
        a = min(a,abs(nums[2]-nums[n-2]));
        a = min(a,abs(nums[3]-nums[n-1]));
        return a;
    }
};

///