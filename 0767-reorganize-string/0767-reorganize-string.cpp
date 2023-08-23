class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        char me;
        int cme=0;
        for(int i=0;i<26;i++){
            if(cme<count[i]){
                cme = count[i];
                me  = i+'a';
            }
        }
        if(cme> n-cme+1)
        return "";
        string ansarr = s;
        int ind=0;
        while(count[me-'a']>0){
            ansarr[ind] = me;
            count[me-'a']--;
            ind+=2;
        }
        for(int i=0;i<26;i++){
            while(count[i]>0){
                if(ind>=n)
                ind=1;
                ansarr[ind] = i+'a';
                count[i]--;
                ind+=2;
            }
        }
        return ansarr;
    }
};