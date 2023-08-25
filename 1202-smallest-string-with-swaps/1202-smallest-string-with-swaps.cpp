class Solution {
public:
    void dfs(string &s, unordered_map<int,vector<int>>&graph,vector<bool>&vis,vector<int>&temp,int ind){
        vis[ind]=true;
        temp.push_back(ind);
        for(auto i:graph[ind]){
            if(!vis[i]){
                dfs(s,graph,vis,temp,i);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>graph;
        for(auto &i:pairs){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        unordered_map<int,char>order;
        vector<bool>vis(s.size(),false);
        for(int i=0;i<s.size();i++){
            if(graph.find(i)!=graph.end() && !vis[i]){
                vector<int>temp;
                dfs(s,graph,vis,temp,i);
                vector<char>tt;
                sort(temp.begin(),temp.end());
                for(auto k:temp){
                    tt.push_back(s[k]);
                    // cout<<k<<endl;
                }
                sort(temp.begin(),temp.end());
                sort(tt.begin(),tt.end());
                for(int j=0;j<tt.size();j++){
                    order[temp[j]] = tt[j];
                }
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(order.find(i)!=order.end()){
                ans+=order[i];
            }
            else ans+=s[i];
        }
        return ans;
    }
};