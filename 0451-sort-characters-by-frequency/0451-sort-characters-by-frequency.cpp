class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char ,int>mp;
        for(char c:s){
            mp[c]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.second>b.second;
        });
        string ans="";
        for(auto it : v){
            for(int i =0;i<it.second;i++){
                ans+=it.first;
            }
        }
        return ans;
    }
};