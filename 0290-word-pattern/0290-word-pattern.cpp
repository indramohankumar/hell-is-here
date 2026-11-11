class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string token ;
        int countwords=0;
        while(getline(ss,token,' ')){
            words.push_back(token);
            countwords++;
        }
        int n =pattern.length();
        if(n!=countwords) return false ;
        unordered_map<string,int>mpp;
        set<char>used;
        for(int i =0;i<n ;i++){
            string word=words[i];
            char ch=pattern[i];
            if(mpp.find(word)==mpp.end()&&used.find(ch)==used.end()){
                used.insert(ch);
                mpp[word]=ch;
            }else if(mpp[word]!=pattern[i]){
                return false ;
            }
            
        }
        return true ;
    }
};