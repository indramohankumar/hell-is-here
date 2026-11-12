class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mpp;
        stringstream ss(s1+" "+s2);
        string token ;
        while(getline(ss,token,' ')){
            mpp[token]++;

        }
        vector<string>ans;
        for(auto it :mpp){
            if(it.second==1){
ans.push_back(it.first);
            }
        }
        return ans;
    }
};