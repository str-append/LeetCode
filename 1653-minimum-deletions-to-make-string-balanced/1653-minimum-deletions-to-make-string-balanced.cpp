class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>acount(n,0);
        int ac=0;
        for(int i=n-1;i>=0;i--){
            acount[i] = ac;
            if(s[i]=='a')
            ac++;
        }
        int countb=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,countb+acount[i]);
            if(s[i]=='b')
            countb++;
        }
        return ans;
    }
};