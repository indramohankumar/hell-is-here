class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        stringstream ss(s);
        string token;
        while(getline(ss,token,' ')){
             reverse(token.begin(),token.end());
            words.push_back(token);
        
        }
       
        string ans;
        for(int i =0;i<words.size() ;i++){
            if(i>0){
               ans+=" ";
            }
             ans+=words[i];
        }
        return ans ;
    }
};