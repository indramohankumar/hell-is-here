class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
     unordered_map<int ,int> freq;
     int n =answerKey.size();
     int  j =0;
     int maxfreq=0;
     int max_len =0;
     for(int i =0;i<n ;i++){
        freq[answerKey[i]]++;
        maxfreq=max(maxfreq,freq[answerKey[i]]);
        while(i-j+1-(maxfreq)>k){
            freq[answerKey[j]]--;
            j++;
        }
        max_len=max(max_len,i-j+1);
     }   
     return max_len;
    }
};