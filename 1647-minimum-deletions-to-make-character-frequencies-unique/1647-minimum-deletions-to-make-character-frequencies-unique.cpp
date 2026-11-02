class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(int ch:s){
            mp[ch]++;
        }
        set<int>st;
        int ans=0;
        for(auto it:mp){
            int freq=it.second;
            while(freq>0&&st.count(freq)){
                freq--;
                ans++;
            }
            st.insert(freq);
        }
        return ans ;
    }
};