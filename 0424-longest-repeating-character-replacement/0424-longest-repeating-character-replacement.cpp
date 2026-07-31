class Solution {
public:
    int characterReplacement(string s, int k) {
        int  n =s.size();
     vector<int> freq(26, 0);
        int  i =0;
        int j =0;
        int maxlength=0;
        int maxfreq=0;
        while(i<n){
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
        
        while(i-j+1-(maxfreq)>k){
            freq[s[j]-'A']--;
            j++;
        }
        maxlength=max(maxlength,i-j+1);
i++;
        }
        return maxlength ;

    }
};