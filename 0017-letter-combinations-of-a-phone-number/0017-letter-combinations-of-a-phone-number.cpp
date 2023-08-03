class Solution {
public:
    void recur(string &digits,vector<string>&ans,string &temp,int ind,unordered_map<int,vector<char>>&map){
        // cout<<ind<<endl;
        if(ind>digits.size()-1){
            ans.push_back(temp);
            return;
        }
        for(auto i:map[digits[ind]-'0']){
            // cout<<i<<endl;
            temp+=i;
            recur(digits,ans,temp,ind+1,map);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string &digits) {
        unordered_map<int,vector<char>>map;
        int j=0;
        for(int i=2;i<=9;i++){
            int n=3;
            if(i==7 || i==9)
            n=4;
            for(int k=0;k<n;k++){
                map[i].push_back(j+'a');
                j++;
            }
        }
        // for(auto i:map){
        //     cout<<i.first<<endl;
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<string>ans;
        string temp="";
        recur(digits,ans,temp,0,map);
        return ans;

    }
};