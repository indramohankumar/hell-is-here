class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mpp;
        sort(hand.begin(),hand.end());
        for(int value:hand){
            mpp[value]++;
        }
        for(int value:hand){
            if(mpp[value]>0){
                for(int i =0;i<groupSize;i++){
                     if(mpp[value + i] == 0) {
                        return false;
                    }
                    mpp[value+i]--;
                }
            }
        }
        return true ;
    }
};