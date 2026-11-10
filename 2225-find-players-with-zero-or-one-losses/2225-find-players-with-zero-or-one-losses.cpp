class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mpp;
        for(auto &match:matches){
            int winner=match[0];
            int loser=match[1];
        
        if(mpp.find(winner)==mpp.end()){
            mpp[winner]=0;
        }
        mpp[loser]++;
    }
                vector<int> notlost;
        vector<int> lostonce;
        for(auto it:mpp){
            if(it.second==0){
                notlost.push_back(it.first);
            }
            if(it.second==1){
                lostonce.push_back(it.first);
            }
        }
          sort(notlost.begin(), notlost.end());
        sort(lostonce.begin(), lostonce.end());

        return {notlost, lostonce};
    }
};