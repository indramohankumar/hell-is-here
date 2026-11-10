class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for( int map:arr){
            mpp[map]++;
            
        }
        unordered_map<int,int>freq;
        for(auto it:mpp){
            freq[it.second]++;
        }
        for(auto it:freq){
            if(it.second>1) return false ;
        }
        return true ;
    }
};