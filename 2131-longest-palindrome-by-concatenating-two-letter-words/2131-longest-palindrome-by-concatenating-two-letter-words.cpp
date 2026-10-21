class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(string& word:words) mp[word]++;

        int result=0;
        bool centreused=false;

        for(string& word:words) {
            string rev=word;
            reverse(rev.begin(),rev.end());

            if(word!=rev) {
                if(mp[word]>0&&mp[rev]>0) {//{ab.....ba}//wala case
                    mp[word]--;
                    mp[rev]--;
                    result+=4;
                }
            }
            else {
                if(mp[word]>=2) {//{aa....aa}//wala case
                    mp[word]-=2;
                    result+=4;
                }
                else if(mp[word]==1&&!centreused) {//odd wala case middle
                    mp[word]--;
                    result+=2;
                    centreused=true;
                }
            }
        }
        return result;
    }
};