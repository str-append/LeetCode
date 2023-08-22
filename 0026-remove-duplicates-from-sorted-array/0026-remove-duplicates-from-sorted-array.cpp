class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        int last = nums[0];
        int i=1;
        while(i<nums.size()){
            int j =i;
            while(j<n && nums[j]==last)
            j++;
            if(j<n){
                last = nums[j];
                nums[p] = nums[j];
                p++;
                j++;
            }
            i=j;
        }
        return p;
        

    }
};