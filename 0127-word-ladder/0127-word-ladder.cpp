class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>set;
        for(auto i:wordList){
            set.insert(i);

        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(word==endWord)
            return lev;
            for(int j=0;j<word.size();j++){
                char org = word[j];
                for(char i='a';i<='z';i++){
                    word[j]=i;
                    if(set.find(word)!=set.end()){
                        q.push({word,lev+1});
                        set.erase(word);
                    }

                }
                word[j]=org;
            }
        }
        return 0;
    }

};