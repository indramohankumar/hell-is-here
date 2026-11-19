class Solution {
public:
    int minimumPushes(string word) {
        int result =0;
        unordered_map<int,int>mpp;
        int key=2;
        for(char &ch:word){
            if(key>9){
                key=2;
            }
            mpp[key]++;
            result+=mpp[key];
            key++;
        }
        return result ;
    }
};