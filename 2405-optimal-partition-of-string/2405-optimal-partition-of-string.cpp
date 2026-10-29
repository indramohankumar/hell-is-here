class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int>mp;
        int count =1;
        for(int i =0;i<s.size();i++){
            if(mp[s[i]]){
                count++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return count;
    }
};