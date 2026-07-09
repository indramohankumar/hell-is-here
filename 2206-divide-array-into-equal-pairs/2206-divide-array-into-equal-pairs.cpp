class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mpp;
        int x =nums.size();
        for(int i=0;i<x;i++){
            mpp[nums[i]]++;
        }
       for (auto it : mpp) {
    if (it.second % 2 != 0)
        return false;
       }
       
    return true ;
}



};