class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;  // q for bfs;
        set<string>st; // for deadends
        for(auto i:deadends) st.insert(i);
        if(st.find("0000")!=st.end()) return -1;
        q.push({"0000",0});
        st.insert("0000");
        while(!q.empty()){
            string s = (q.front()).first;
            int tries = (q.front()).second;
            if(s==target)
            return tries;
            q.pop();
            for(int i=0;i<4;i++){
                string temp =s;
                if(s[i]!='9'){ // if 9 is there we can not simply increase
                    temp[i]=(char)((int)s[i]+1);
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push({temp,tries+1});
                    }
                }
                if(s[i]!='0'){ // if 0 is there we can not simply decrease
                    temp[i]=(char)((int)s[i]-1);
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push({temp,tries+1});
                    }
                }
                if(s[i]=='9'){
                    temp[i]='0'; //if 9 we can increase to 0
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push({temp,tries+1});
                    }
                }
                if(s[i]=='0'){ //if 0 we can decrease to 9
                    temp[i]='9';
                    if(st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push({temp,tries+1});
                    }
                }
            }
        }
        return -1;
    }
};