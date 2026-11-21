class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false ;
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(int value:nums){
            mpp[value]++;
        }
    for(int value:nums){
        if(mpp[value]>0){
            for(int i =0;i<k;i++){
                if(mpp[value+i]==0){
                    return false  ;
                }
                mpp[value+i]--;
            }
        }
    }
    return true;
    }
};