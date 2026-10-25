class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int result =0;
        bool centerused=false;
        for(auto it:mp){
            if(it.second%2==0){
                result+=it.second;

            }
            else {
                result+=it.second-1;
                if(!centerused){
                    result++;
                    centerused=true;
                }
            }
        }
        return result ;
    }
};