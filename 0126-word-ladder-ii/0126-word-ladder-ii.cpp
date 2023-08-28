class Solution {
public:

    void dfs(string &word, unordered_map<string,int>&map,vector<vector<string>>&ans,vector<string>&temp,string &bw){
        string original = word;
        temp.push_back(word);
        if (original ==bw){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
        }
        else{
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(map.find(word)!=map.end() && map[word]<map[original]){
                        dfs(word,map,ans,temp,bw);
                    }
                }
                word[i] = org;
            }
        }
        temp.pop_back();
    }
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        vector<vector<string>>ans;
        queue<string>q;
        unordered_set<string>st(wl.begin(),wl.end());
        unordered_map<string,int>map;
        q.push(bw);
        int level =0;
        st.erase(bw);
        while(!q.empty()){
            int n = q.size();
            level++;
            for(int i=0;i<n;i++){
                auto word  = q.front();
                map[word] = level;
                q.pop();
                if(word == ew){
                    break;
                }
                for(int j=0;j<word.size();j++){
                    char w = word[j];
                    for(char k='a';k<='z';k++){
                        if(k!=w){
                            word[j] = k;
                            if(st.find(word)!=st.end()){
                                q.push(word);
                                st.erase(word);
                            }
                        }
                    }
                    word[j] = w;
                }
            }

        }
        vector<string>temp;
        dfs(ew,map,ans,temp,bw);
        return ans;
    }
};