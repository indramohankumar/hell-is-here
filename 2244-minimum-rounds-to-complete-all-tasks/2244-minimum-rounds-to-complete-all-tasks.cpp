class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int count=0;
        for( int task:tasks){
            mp[task]++;
        }
        for(auto it :mp){
            if(it.second==1) return -1;
            count+=ceil(it.second/3.0);
        }
        return count;
    }
};