class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
       
        for(int nums:arr){
            mpp[nums]++;
        }
         int count=mpp.size();
        vector<int>val;
        for(auto it:mpp){
            val.push_back(it.second);
        }
        sort(val.begin(),val.end());
        for(int i =0;i<val.size();i++){
            if(k>=val[i]){
                k-=val[i];
                count--;
            }
            else {
                break ;
            }
        }
        return count ;
    }
};