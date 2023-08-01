class Solution {
public:
    bool isvalid(string &s){
        if(s.back()=='.')
        return false;
        int temp=0;
        // cout<<s<<" in isvalid "<<endl;
        string temps="";
        for(int i=0;i<s.size()-1;i++){
            if((s[i]=='.' && s[i+1]=='.'))
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                temp=temp*10 + (s[i]-'0');
                temps+=s[i];
            }
            else{
                // cout<<temp<<" i "<<i<< endl;
                temp=0;
                temps="";
            }
            if(temps.front()=='0' && temps.size()>1)
            return false;
            if(temp>255)
            return false;
        }
        return true;
    }
    void recur(string s,int i,string temp,vector<string>&ans,int dc){
        if(dc>3||temp.size()>15) //3*4 + 3(dots)
        return;
        if(dc==3 && (i>=s.size() || temp.size()>s.size()+3)){
            // cout<<temp<<endl;
            if(isvalid(temp))
            ans.push_back(temp);
            return;
        }
        string a = temp;
        if(temp.back()!='.' && temp!=""){
            a+='.';
            recur(s,i,a,ans,dc+1);
        }
        string b = temp;
        b+=s[i];
        recur(s,i+1,b,ans,dc);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string t="";
        int dc=0;
        recur(s,0,t,ans,dc);
        return ans;
    }
};