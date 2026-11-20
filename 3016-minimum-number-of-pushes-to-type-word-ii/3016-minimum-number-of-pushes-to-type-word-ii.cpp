class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mpp(26,0);
        for(char &ch:word){
            mpp[ch-'a']++;
        }
        sort(begin(mpp),end(mpp),greater<int>());//decreasing order of frequmicies 
        int result=0;
        for(int i =0;i<26;i++){
            int freq=mpp[i];
            int press=i/8+1;
            result +=press*freq;
        }
        return result ;
    }
};