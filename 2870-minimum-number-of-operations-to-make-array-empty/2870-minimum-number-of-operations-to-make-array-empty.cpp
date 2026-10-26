class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=0;
        for(int num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second==1) return -1;
            count+=ceil(it.second/3.0);
        }
        return count ;
    }
};