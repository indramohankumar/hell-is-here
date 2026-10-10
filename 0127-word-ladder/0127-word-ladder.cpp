class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()){
            return 0;

        }
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>visited;
        visited.insert(beginWord);
        int steps=1;
        while(!q.empty()){
            int n=q.size();
            for(int i =0;i<n;i++){
                string current=q.front();
                q.pop();
                if(current==endWord){
                    return steps;
                }
                for(const string&word :words){
                    if(visited.find(word)!=visited.end()){
                        continue;
                    }
                    int diff=0;
                    for(int j=0;j<current.size();j++){
                        if(current[j]!=word[j]){
                            diff++;
                        }
                    }
                    if(diff==1){
                        visited.insert(word);
                        q.push(word);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};