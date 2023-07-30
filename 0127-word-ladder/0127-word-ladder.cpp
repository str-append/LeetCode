class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(word==endWord)
            return lev;
            for(int i=0;i<word.size();i++){
                char org =word[i];
                for(char j='a';j<='z';j++){
                    word[i] =j;
                    if(s.find(word)!=s.end())
                    q.push({word,lev+1});
                    s.erase(word);
                }
                word[i]=org;
            }
        }
        return 0;
    }
};