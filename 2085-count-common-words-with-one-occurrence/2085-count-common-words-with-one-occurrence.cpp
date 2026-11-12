class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mpp1;
        unordered_map<string,int>mpp2;
        for(string word :words1){
            mpp1[word]++;
        }
        for(string word :words2){
            mpp2[word]++;
        }
        int countwords=0;
        for(auto it :mpp1){
            if(it.second==1&&mpp2[it.first]==1){
                countwords++;
            }
        }
        return countwords;
        
    }
};